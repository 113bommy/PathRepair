#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, P;
  cin >> N >> P;
  ll i=2, l=1;
  
  while (P != 1) {
    if (P % i == 0) {
      ll ni = 0;
      while (P%i == 0) {
        ni++;
        P /= i;
      }
      l *= pow(i, ni / N);
    } else if (i*i > P) {
      if (N == 1) l *= N;
      break
    } else {
      i++;
    }
  }
  cout << l << endl;
}