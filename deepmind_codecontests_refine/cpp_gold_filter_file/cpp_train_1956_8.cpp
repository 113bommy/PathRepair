#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n, k;
  cin >> n >> k;
  n %= k;
  cout << min(n, k - n) << endl;
}
