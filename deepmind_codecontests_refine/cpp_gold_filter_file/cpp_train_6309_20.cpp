#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long n, k, c;
  cin >> n >> k;
  c = n / k;
  if (c % 2 == 1)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
