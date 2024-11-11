#include <bits/stdc++.h>
using namespace std;
const long long N = 1e0 + 9;
long long n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr << "‌";
  cin >> n >> m;
  if (m < n) swap(n, m);
  cout << ((n & 1) ? "Akshat" : "Malvika");
}
