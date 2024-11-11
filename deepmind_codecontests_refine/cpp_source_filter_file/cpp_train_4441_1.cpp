#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100024;
int s[MAX_N], k[MAX_N];
vector<int> v[MAX_N];
bool used[MAX_N];
int main() {
  int n, ans = 0, p;
  cin >> n;
  s[0] = 1;
  for (int i = 1; i < n; i++) {
    cin >> p;
    s[i] = s[p - 1] + 1;
  }
  for (int i = 0; i < n; i++) {
    k[s[i]]++;
  }
  for (int i = 0; i < n; i++) ans += k[i] % 2;
  cout << ans << endl;
  return 0;
}
