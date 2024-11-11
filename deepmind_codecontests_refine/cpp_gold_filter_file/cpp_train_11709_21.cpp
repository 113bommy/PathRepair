#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool uin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 2000;
bitset<N> ans[N];
bitset<N> input[N];
void div2(vector<int>& a) {
  int c = 0;
  for (int i = (int)(a.size()) - 1; i >= 0; --i) {
    c *= 10;
    c += a[i];
    a[i] = c / 2;
    c %= 2;
  }
}
void norm(vector<int>& a) {
  while (!a.empty() && a.back() == 0) a.pop_back();
}
void solve() {
  int m;
  cin >> m;
  for (int i = 0; i < (int)(m); ++i) {
    string s;
    cin >> s;
    reverse((s).begin(), (s).end());
    vector<int> a(s.length());
    for (int i = 0; i < (int)(a.size()); ++i) a[i] = s[i] - '0';
    int k = 0;
    while (!a.empty()) {
      if (a[0] & 1) input[i].set(k);
      div2(a);
      norm(a);
      ++k;
    }
  }
  vector<int> hi(N, -1);
  for (int i = 0; i < (int)(m); ++i) {
    int j = N - 1;
    while (j >= 0) {
      if (input[i].test(j)) {
        if (hi[j] != -1) {
          input[i] ^= input[hi[j]];
          ans[i] ^= ans[hi[j]];
        } else
          break;
      }
      --j;
    }
    if (j < 0) {
      vector<int> out;
      for (int k = 0; k < (int)(m); ++k)
        if (ans[i].test(k)) out.push_back(k);
      cout << out.size();
      for (int x : out) cout << ' ' << x;
      cout << '\n';
    } else {
      cout << 0 << '\n';
      ans[i].flip(i);
      hi[j] = i;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;
  cout.precision(15);
  cerr << fixed;
  cerr.precision(15);
  solve();
  return 0;
}
