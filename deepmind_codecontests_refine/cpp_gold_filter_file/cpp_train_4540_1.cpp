#include <bits/stdc++.h>
using namespace std;
const long long N = 262160, MOD = 1e9 + 7, MX = 1e9 + 9;
int n, m, a[N], T, k, x, q, cnt = 1;
long long ans;
string s;
stack<int> st;
vector<int> v;
bool vis[101][101], flag;
int main() {
  scanf("%d", &q);
  q *= 2;
  while (q--) {
    cin >> s;
    if (s == "add") {
      cin >> x;
      st.push(x);
    } else {
      if (!st.empty()) {
        if (st.top() == cnt)
          st.pop();
        else {
          while (!(st.empty())) st.pop();
          ans++;
        }
      }
      cnt++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
