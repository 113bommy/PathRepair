#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 0;
  cin >> n;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    sum += a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  long long o = sum;
  for (long long i = 0; i < n; i++) {
    o += sum;
    sum -= v[i];
  }
  cout << o;
  return 0;
}
