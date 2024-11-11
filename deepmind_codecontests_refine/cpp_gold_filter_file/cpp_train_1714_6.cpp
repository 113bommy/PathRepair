#include <bits/stdc++.h>
using namespace std;
long long int n, t, arr[200009 + 10], brr[200009 + 10], crr[200009 + 10];
vector<long long int> v;
int main() {
  for (int i = 0; i < 3; i++) scanf("%lld", &n), v.push_back(n);
  sort(v.begin(), v.end());
  long long int a = (v[2] - v[1]);
  long long int b = v[1] - v[0];
  long long int c = min(a, b);
  t = c;
  v[1] -= c;
  v[2] -= (2 * c);
  if (v[1] == v[2]) {
    t += ((v[0] + v[1] + v[2]) / 3);
  } else {
    a = 2 * v[1];
    if (4 * v[0] <= v[2])
      t += a;
    else
      t += ((v[0] + v[1] + v[2]) / 3);
  }
  printf("%lld\n", t);
  return 0;
}
