#include <bits/stdc++.h>
using namespace std;
int main() {
  long i, n;
  scanf("%ld", &n);
  vector<long long> v;
  while (n--) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  set<long long> s;
  for (i = 0; i < v.size(); i++) {
    while (v[i] % 2 == 0) v[i] /= 2;
    while (v[i] % 3 == 0) v[i] /= 3;
    s.insert(v[i]);
  }
  if (s.size() == 1)
    printf("Yes");
  else
    printf("No");
  return 0;
}
