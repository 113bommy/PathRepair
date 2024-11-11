#include <bits/stdc++.h>
using namespace std;
long long int besar(long long int a, long long int b) {
  if (a > b) {
    return (a);
  } else {
    return (b);
  }
}
int main() {
  long long int warga;
  long long int maxi = INT_MIN;
  long long int sum = 0;
  cin >> warga;
  for (int i = 1; i <= warga; i++) {
    int a;
    cin >> a;
    sum += a;
    maxi = besar(maxi, a);
  }
  long long int jawaban;
  long long int total = maxi * warga;
  if (warga > 1) {
    if (sum != total) {
      jawaban = total - sum;
    } else {
      jawaban = sum;
    }
  } else {
    jawaban = 0;
  }
  cout << jawaban << "\n";
}
