#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int tc;
  cin >> tc;
  while (tc--) {
    long long int n, x;
    cin >> n >> x;
    long long int ar[n];
    long long int nodd = 0, neven = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> ar[i];
      if (ar[i] & 1)
        nodd++;
      else
        neven++;
    }
    long long int flag = 0;
    for (long long int i = 0; i <= nodd; i++) {
      if (i % 2 == 0 || i > x) continue;
      if (i + neven >= x) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
}
