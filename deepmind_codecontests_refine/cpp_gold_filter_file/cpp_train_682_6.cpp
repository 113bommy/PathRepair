#include <bits/stdc++.h>
using namespace std;
long long int ar[123456], br[123456];
vector<long long int> v;
map<long long int, long long int> mpa, mpb;
map<string, long long int> mps;
map<char, long long int> mpc;
int main() {
  long long int i, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> ar[i];
    mpa[ar[i]]++;
  }
  for (i = 0; i < n; i++) {
    cin >> br[i];
    mpb[br[i]]++;
  }
  long long int cnt = 0;
  for (i = 1; i <= 5; i++) {
    if ((mpa[i] + mpb[i]) % 2 == 1) {
      cout << -1 << endl;
      return 0;
    }
    cnt += abs(mpa[i] - mpb[i]);
  }
  cout << cnt / 4 << endl;
  return 0;
}
