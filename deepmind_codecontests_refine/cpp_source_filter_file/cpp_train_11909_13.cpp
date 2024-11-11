#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int digit;
  vector<long long int> sayilar, sayilar2;
  cin >> digit;
  if (digit & 1 == 0) {
    cout << -1;
    return 0;
  }
  for (long long int i = 0; i < digit; i++) {
    sayilar.push_back(i);
  }
  for (long long int i = 0; i < digit; i++) {
    sayilar2.push_back((sayilar[i] * 2) % digit);
  }
  for (long long int i = 0; i < digit; i++) {
    cout << sayilar[i] << " ";
  }
  cout << endl;
  for (long long int i = 0; i < digit; i++) {
    cout << sayilar[i] << " ";
  }
  cout << endl;
  for (long long int i = 0; i < digit; i++) {
    cout << sayilar2[i] << " ";
  }
}
