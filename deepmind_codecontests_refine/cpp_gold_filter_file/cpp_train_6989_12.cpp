#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long k;
  cin >> k;
  long long second = 2000 + k;
  long long ar[2000];
  ar[0] = -1;
  for (long long int i = 1; i < 2000; i++) {
    if (second <= 1000000) {
      ar[i] = second;
      second = 0;
    } else {
      ar[i] = 1000000;
      second -= 1000000;
    }
  }
  cout << 2000 << '\n';
  for (long long int i = 0; i < 2000; i++)
    cout << ar[i] << ((i == (2000 - 1)) ? '\n' : ' ');
  return 0;
}
