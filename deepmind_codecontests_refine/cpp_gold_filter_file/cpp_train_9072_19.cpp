#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long n;
  cin >> n;
  cout << (n + 2) / 2 << endl;
  long long l = 1;
  long long r = 1;
  for (long long i = 0; i < n; i++) {
    cout << l << " " << r << endl;
    if (i % 2 == 0)
      r++;
    else
      l++;
  }
  return 0;
}
