#include <bits/stdc++.h>
using namespace std;
void HoH() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
long long arr[9000009];
int main() {
  HoH();
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr[x]++;
  }
  long long res = 0, c = 0;
  for (int i = 0; i < 9000009; i++) {
    res += arr[i];
    c += res % 2;
    res /= 2;
  }
  cout << c;
  return 0;
}
