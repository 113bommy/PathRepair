#include <bits/stdc++.h>
using namespace std;
bool prime(long long v) {
  if (v == 2) return true;
  if (v % 2 == 0) return false;
  for (long long i = 3; i * i < v; i++)
    if (v % i == 0) return false;
  return true;
}
int main() {
  long long k, limit, p;
  vector<long long> bs;
  cin >> k;
  limit = 2 * k * k;
  p = 1;
  while (bs.size() < k) {
    p++;
    while (!prime(p)) p++;
    bs.push_back(p);
    for (long long i = 0; i < bs.size(); i++)
      if (bs[i] * p <= limit) bs.push_back(bs[i] * p);
  }
  sort(bs.begin(), bs.end(), greater<long long>());
  for (long long i = 0; i < k; i++) cout << (i ? " " : "") << bs[i];
  cout << endl;
  return 0;
}
