#include <bits/stdc++.h>
using namespace std;
map<long long, int> d;
long long n, dem = 0, sum, maxx;
int main() {
  cin >> n;
  sum = 0;
  maxx = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum = sum + a;
    d[sum]++;
    if (d[sum] > maxx) maxx = d[sum];
  }
  cout << n - maxx;
  return 0;
}
