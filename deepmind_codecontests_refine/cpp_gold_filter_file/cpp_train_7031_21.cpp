#include <bits/stdc++.h>
#pragma comment(linker, "/stack:67108864")
using namespace std;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
const long long INF = 1e15;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  ifstream ifile("input.txt");
  if (ifile) {
    freopen("input.txt", "rt", stdin);
  }
  vector<long long> a(4);
  while (cin >> a[0]) {
    for (int i = 1; i <= int(3); ++i) cin >> a[i];
    sort((a).begin(), (a).end());
    vector<long long> b(2);
    for (int i = 0; i < int(2); ++i) cin >> b[i];
    sort((b).begin(), (b).end());
    cout << max(0, min(a[0], b[1] + 1) - b[0]) << endl;
  }
  return 0;
}
