#include <bits/stdc++.h>
using namespace std;
void input() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void slove() {
  long long n;
  cin >> n;
  cout << n << " ";
  for (int i = 1; i < n; i++) {
    cout << 2 * n + i << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    slove();
  }
  return 0;
}
