#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926535897932384626;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long k;
  cin >> k;
  cout << 2 << " " << 3 << endl;
  long long lol = (1LL << 17);
  cout << (lol | k) << " " << k << " 0" << endl;
  cout << lol << " " << (lol | k) << " k" << endl;
  return 0;
}
