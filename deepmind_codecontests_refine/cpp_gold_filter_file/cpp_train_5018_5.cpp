#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, cevap = 0, mutlak;
  cin >> n;
  long long int dizi[n], dizi2[n];
  for (int i = 0; i < n; i++) {
    cin >> dizi[i] >> dizi2[i];
    mutlak = abs(dizi[i] - dizi2[i]);
    if (mutlak >= 5) {
      cevap += (mutlak / 5);
      mutlak -= (mutlak / 5) * 5;
    }
    if (mutlak >= 2) {
      cevap += (mutlak / 2);
      mutlak -= (mutlak / 2) * 2;
    }
    if (mutlak == 1) {
      cevap += 1;
    }
    cout << cevap << endl;
    cevap = 0;
  }
}
