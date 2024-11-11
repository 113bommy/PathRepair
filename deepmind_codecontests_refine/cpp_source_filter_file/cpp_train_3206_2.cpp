#include <bits/stdc++.h>
using namespace std;
int main()
{
  int64_t a, b, k;
  cin >> a >> b >> k;
  cout << max(0LL, (a - k)) << ' ' << max(0LL, (b - max(0LL, (k - a)))) << endl;
}