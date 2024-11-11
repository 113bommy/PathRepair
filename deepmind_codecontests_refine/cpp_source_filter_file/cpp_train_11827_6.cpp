#include <bits/stdc++.h>
using namespace std;
long long n, s, x;
vector<long long> v;
long long f(int k) {
  long long p = 0;
  vector<long long> u;
  for (int i = 0; i < n; i++) u.push_back(v[i] + (i + 1) * k);
  sort(u.begin(), u.end());
  for (int i = 0; i < k; i++) p += u[i];
  return p;
}
long long bs() {
  long long sup = n;
  long long inf = 0;
  long long mid = 0;
  while (sup > inf) {
    mid = (sup + inf + 1) / 2;
    if (f(mid) > s)
      sup = mid - 1;
    else
      inf = mid;
  }
  return inf;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  int r = bs();
  cout << r << " " << f(r);
}
