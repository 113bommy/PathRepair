#include <bits/stdc++.h>
using namespace std;
long long types[400];
int main() {
  long long n, p;
  cin >> p >> n;
  for (long long i = 0; i < 350; i++) types[i] = 0;
  long long conf = -1;
  long long dum = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    a = (a % p);
    if (types[a] == 1 && dum == 0) {
      conf = i;
      dum = 1;
    }
    types[a]++;
  }
  cout << conf;
  return 0;
}
