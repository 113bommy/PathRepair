#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> A(3), B(3);
  for (int i = 0; i < 3; ++i) cin >> A[i];
  for (int i = 0; i < 3; ++i) cin >> B[i];
  int cnt = 0;
  for (int i = 0; i < 3; ++i) {
    cnt += A[i] == B[i];
  }
  if (cnt >= 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
