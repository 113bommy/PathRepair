#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long Pres[n];
  for (int i = 0; i < n; i++) {
    cin >> Pres[n];
    if (Pres[n] % 2 == 0) Pres[n]--;
    cout << Pres[n] << ' ';
  }
  return 0;
}
