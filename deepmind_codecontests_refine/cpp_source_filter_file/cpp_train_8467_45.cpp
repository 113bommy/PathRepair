#include <bits/stdc++.h>
using namespace std;
unsigned long long int F[65];
int main() {
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < 65; i++) F[i] = F[i - 1] + F[i - 2];
  unsigned long long int a;
  vector<unsigned long long int> V;
  cin >> a;
  for (int i = 1; i < 65; i++) {
    for (int j = 1; j < 65; j++) {
      for (int k = 1; k < 65; k++) {
        if (a == F[i] + F[j] + F[k]) {
          cout << F[i] << " " << F[j] << " " << F[k] << endl;
          a -= (F[i] + F[j] + F[k]);
        }
      }
    }
  }
  if (a != 0) printf("I'm too stupid to solve this problem");
  return 0;
}
