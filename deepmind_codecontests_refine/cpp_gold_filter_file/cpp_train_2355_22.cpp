#include <bits/stdc++.h>
using namespace std;
const int pw = 131072;
int main() {
  int n, m;
  ios::sync_with_stdio(0);
  cin >> n >> m;
  if (n == 2 && m == 0) {
    cout << "NO";
    return 0;
  } else
    cout << "YES\n";
  if (n == 1) {
    cout << m;
    return 0;
  }
  if (n == 2) {
    cout << "0 " << m;
    return 0;
  }
  int xuanxue = 0;
  for (int i = 1; i <= n - 3; i++) cout << i << " ", xuanxue = xuanxue ^ i;
  if (m == xuanxue) {
    cout << pw << " " << pw * 2 << " " << (pw ^ (pw * 2));
  } else
    cout << "0 " << pw << " " << ((pw ^ m) ^ xuanxue);
  return 0;
}
