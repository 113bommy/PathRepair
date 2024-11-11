#include <bits/stdc++.h>
long long int N[100100];
long long int NN[100100];
long long int n, p;
using namespace std;
void init(long long int n) {
  for (long long int i = 0; i <= n; i++) {
    NN[i] = 0;
  }
  NN[0] = N[0];
  for (long long int i = 1; i < n; i++) {
    NN[i] = (NN[i - 1] + N[i]);
  }
}
int main() {
  while (cin >> n >> p) {
    long long int SUM = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> N[i];
    }
    for (long long int i = 1; i < n; i++) {
      SUM = (SUM + N[i]) % p;
    }
    init(n);
    long long int k;
    long long int maxx;
    maxx = N[0] % p + SUM;
    for (long long int k = 1; k <= n; k++) {
      long long int max2 = 0, max3 = 0;
      max2 = NN[k] % p;
      max3 = (NN[n - 1] - NN[k]) % p;
      if (maxx < max2 + max3) {
        maxx = max2 + max3;
      }
    }
    cout << maxx << endl;
  }
}
