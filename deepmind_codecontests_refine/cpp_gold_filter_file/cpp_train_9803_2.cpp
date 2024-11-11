#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const int N = 1e5 + 1;
string s;
int c[N];
vector<int> a;
int n;
void seive() {
  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (!c[i]) {
      for (int j = i; j <= n; j += i) {
        if (!c[j]) c[j] = cnt;
      }
      cnt++;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  seive();
  for (int i = 2; i <= n; i++) cout << c[i] << ' ';
  cout << '\n';
}
