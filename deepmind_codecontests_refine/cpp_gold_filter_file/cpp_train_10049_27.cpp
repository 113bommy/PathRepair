#include <bits/stdc++.h>
using namespace std;
void HoH() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  HoH();
  long long n, k, c = 0;
  cin >> n >> k;
  k *= 2;
  while (k-- && n--) {
    c += n;
  }
  cout << c;
  return 0;
}
