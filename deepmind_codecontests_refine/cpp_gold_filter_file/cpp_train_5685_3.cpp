#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int cnt[N];
void solve(int n) {
  if (n == 3) {
    cout << "3 1 2 3" << endl << "3 1 2 3";
    return;
  }
  if (n == 4) {
    cout << "4 1 2 3 4" << endl << "4 1 3 2 4" << endl << "4 1 2 4 3";
    return;
  }
  cout << "3 " << n << " " << n - 1 << " " << n - 2 << endl;
  cout << "3 " << n << " " << n - 1 << " " << n - 2 << endl;
  for (int i = 1; i < n - 3; i++)
    cout << "4 " << i << " " << n - 1 << " " << i + 1 << " " << n << endl;
  cout << "4 1 " << n - 1 << " " << n - 3 << " " << n << endl;
  solve(n - 2);
}
int main() {
  int n;
  cin >> n;
  cnt[3] = 2;
  cnt[4] = 3;
  for (int i = 5; i <= n; i++) cnt[i] = cnt[i - 2] + i - 1;
  cout << cnt[n] << endl;
  solve(n);
}
