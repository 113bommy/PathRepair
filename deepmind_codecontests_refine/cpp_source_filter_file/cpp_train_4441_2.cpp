#include <bits/stdc++.h>
using namespace std;
long long mod = 27449;
int inf = 1e9;
double eps = 1e-2;
ifstream in("input.txt");
ofstream out("output.txt");
long long ans = 0;
vector<int> d;
vector<int> d1;
int main() {
  int n;
  cin >> n;
  d.resize(n);
  d1.resize(n);
  d[0] = 0;
  d1[0] = 1;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    d[i] = d[p - 1] + 1;
    d1[d[i]]++;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += d1[i] % 2;
    if (d1[i] == 0) break;
  }
  cout << ans;
  return 0;
}
