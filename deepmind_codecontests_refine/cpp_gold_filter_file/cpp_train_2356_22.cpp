#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long n, t;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long temp;
  vector<long long> a;
  while (n--) cin >> temp, a.push_back(temp);
  long long cnt = 0;
  for (long long i = 1; i < a.size() - 1; i++) {
    if (a[i] > a[i - 1] and a[i] > a[i + 1])
      cnt++;
    else if (a[i] < a[i - 1] and a[i] < a[i + 1])
      cnt++;
  }
  cout << cnt;
}
