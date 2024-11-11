#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed;
  cout.precision(10);
  ;
  int n;
  cin >> n;
  int cnt = 0, a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    cnt += (a & 1);
  }
  cout << cnt ? "First" : "Second";
  return 0;
}
