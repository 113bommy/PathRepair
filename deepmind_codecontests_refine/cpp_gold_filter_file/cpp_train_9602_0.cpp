#include <bits/stdc++.h>
using namespace std;
void dout() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << " " << H;
  dout(T...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3003, K = 3000003;
int n, k, a[N], used[N];
vector<int> vec[K], v;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> k;
  char c;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    if (c == 'R') {
      a[i] = 1;
    } else {
      a[i] = 0;
    }
  }
  int cur = 0, z = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] == 0) {
      z++;
    } else {
      cur += z;
      if (i < n && a[i + 1] == 0) {
        v.push_back(i);
        used[i] = 1;
      }
    }
  }
  if (k > cur) {
    cout << -1;
    return 0;
  }
  int cnt = 1;
  stack<int> st;
  while (k > 0) {
    int l = min((int)v.size(), cur - k + 1);
    cur -= l;
    k--;
    while (l--) {
      int pos = v.back();
      vec[cnt].push_back(pos);
      a[pos] = 0, a[pos + 1] = 1;
      st.push(pos);
      used[pos] = 0;
      v.pop_back();
    }
    while (!st.empty()) {
      int pos = st.top();
      if (!used[pos + 1] && pos + 1 < n && a[pos + 1] == 1 && a[pos + 2] == 0) {
        v.push_back(pos + 1);
        used[pos + 1] = 1;
      }
      if (!used[pos - 1] && a[pos - 1] == 1 && a[pos] == 0) {
        v.push_back(pos - 1);
        used[pos - 1] = 1;
      }
      st.pop();
    }
    cnt++;
  }
  if (cur == 0) {
    for (int i = 1; i < cnt; i++) {
      cout << vec[i].size() << ' ';
      for (int j : vec[i]) {
        cout << j << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << -1;
  }
}
