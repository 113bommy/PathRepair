#include <bits/stdc++.h>
using namespace std;
int a[100009], b[100009];
void slove() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[a[i]];
  for (int i = 1; i <= n; i++) cout << b[a[i]] << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  slove();
  return 0;
}
