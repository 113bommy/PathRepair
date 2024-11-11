#include <bits/stdc++.h>
using namespace std;
set<long long> s;
int main() {
  long long a, maxi = -85, mini = 10e10;
  cin >> a;
  long long x[a];
  for (long long i = 0; i < a; i++) {
    cin >> x[i];
    maxi = max(maxi, x[i]);
    mini = min(mini, x[i]);
  }
  long long sum = 0;
  for (long long i = 0; i < a; i++) {
    if (x[i] == mini || x[i] == maxi) sum++;
  }
  cout << a - sum;
}
