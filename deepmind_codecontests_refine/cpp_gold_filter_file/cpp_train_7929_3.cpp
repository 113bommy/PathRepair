#include <bits/stdc++.h>
using namespace std;
void In_Out() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  int n, m;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  int b[m];
  for (int i = 0; i < m; i++) cin >> b[i];
  int max_a = INT_MIN;
  int max_b = INT_MIN;
  for (int i = 0; i < n; i++) max_a = max(max_a, a[i]);
  for (int i = 0; i < m; i++) max_b = max(max_b, b[i]);
  cout << max_a << " " << max_b;
}
