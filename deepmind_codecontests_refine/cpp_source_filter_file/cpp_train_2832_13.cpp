#include <bits/stdc++.h>
using namespace std;
template <class Monoid>
struct SegTree {
  int N;
  vector<Monoid> node;
  std::function<Monoid(Monoid, Monoid)> operation;
  Monoid unit;
  std::function<bool(Monoid, Monoid)> comp;
  Monoid not_find_sgn;
  SegTree(vector<Monoid>& data, std::function<Monoid(Monoid, Monoid)> op,
          Monoid U) {
    operation = op;
    unit = U;
    int size = data.size();
    N = 1;
    while (N < size) N <<= 1;
    node.resize(2 * N - 1, unit);
    for (int i = 0; i < size; i++) {
      node[i + N - 1] = data[i];
    }
    for (int i = N - 2; i >= 0; i--) {
      node[i] = operation(node[i * 2 + 1], node[i * 2 + 2]);
    }
  }
  SegTree() = default;
  void update(int pos, Monoid val) {
    pos += N - 1;
    node[pos] = val;
    while (pos > 0) {
      pos = (pos - 1) / 2;
      node[pos] = operation(node[pos * 2 + 1], node[pos * 2 + 2]);
    }
  }
  Monoid getval(int a, int b, int idx, int l, int r = -1) {
    if (r == -1) r = N;
    if (b <= l || r <= a) return unit;
    if (a <= l && r <= b) return node[idx];
    Monoid left = getval(a, b, idx * 2 + 1, l, (l + r) / 2);
    Monoid right = getval(a, b, idx * 2 + 2, (l + r) / 2, r);
    return operation(left, right);
  }
  Monoid getval(int a, int b) { return getval(a, b, 0, 0, -1); }
};
long long tentousu(string& a, string& b) {
  queue<int> num[26];
  for (int i = 0; i < a.size(); i++) num[a[i] - 'a'].push(i);
  vector<int> ar(a.size(), 0);
  for (int i = 0; i < b.size(); i++) {
    ar[i] = num[b[i] - 'a'].front();
    num[b[i] - 'a'].pop();
  }
  vector<int> tmp(a.size(), 0);
  SegTree<int> st(
      tmp, [](int a, int b) { return a + b; }, 0);
  long long ret = 0;
  for (int i = 0; i < ar.size(); i++) {
    ret += st.getval(0, ar[i]);
    st.update(ar[i], 1);
  }
  return ret;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s, t, target;
    cin >> s >> t;
    vector<int> cnt_ch(26, 0);
    for (int i = 0; i < s.size(); i++)
      cnt_ch[s[i] - 'a']++, target.push_back(s[i]);
    for (int i = 0; i < t.size(); i++) cnt_ch[t[i] - 'a']--;
    bool f = true;
    for (int i = 0; i < 26; i++) {
      if (cnt_ch[i] < 0 && f) {
        cout << "NO"
             << "\n";
        f = false;
      }
    }
    if (!f) continue;
    for (int i = 0; i < s.size(); i++) {
      cnt_ch[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (cnt_ch[i] >= 2 && f) {
        cout << "YES"
             << "\n";
        f = true;
      }
    }
    if (!f) continue;
    sort(target.begin(), target.end());
    if (tentousu(target, s) % 2 == tentousu(target, t) % 2) {
      cout << "YES"
           << "\n";
    } else
      cout << "NO"
           << "\n";
  }
  return 0;
}
