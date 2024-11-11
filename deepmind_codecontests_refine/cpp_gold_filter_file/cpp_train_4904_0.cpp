#include <bits/stdc++.h>
using namespace std;
long double dis(double x, double y, double x1, double y1) {
  return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
double PI = sqrt((double)2);
double e = 2.718281828;
void EnGz() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int GCD_(long long a, long long b) { return b ? GCD_(b, a % b) : a; }
int main() {
  EnGz();
  int n;
  cin >> n;
  long long int s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++)
    if (i & 1)
      s1 += i;
    else
      s2 += i;
  if (GCD_(s1, s2) > 1) {
    cout << "Yes\n";
    cout << n / 2 + bool(n & 1) << " ";
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    cout << endl;
    cout << n / 2 << " ";
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    cout << endl;
  } else
    cout << "No\n";
  return 0;
}
