#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt += a;
  }
  if (cnt == k - 2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
