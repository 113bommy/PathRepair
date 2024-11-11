#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 922337203685477;
const long long mininf = -922337203685477;
const long long nax = 1e7;
long long n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (long long i = nax - n + 1; i <= nax; i++) {
    cout << i << " ";
  }
  cout << '\n';
}
