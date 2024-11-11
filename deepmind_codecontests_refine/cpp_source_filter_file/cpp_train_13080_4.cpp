#include <bits/stdc++.h>
using namespace std;
const int DJLFO = 111111;
long long n, s, f;
long long a[DJLFO];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> s >> f;
  long long sum = 0;
  for (int i = s; i < f; i++) {
    sum += a[i];
  }
  int Max = sum, MaxN = 1;
  int curs = s, curf = f;
  for (int i = n; i >= 2; i--) {
    sum = sum - a[curs] + a[curf];
    if (sum > Max) {
      Max = sum;
      MaxN = i;
    }
    curs++;
    curf++;
    if (curf == n + 1) {
      curf = 1;
    }
    if (curs == n + 1) {
      curs = 1;
    }
  }
  cout << MaxN << endl;
  return 0;
}
