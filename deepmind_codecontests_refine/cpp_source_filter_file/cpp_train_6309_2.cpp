#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (((n + n % k) / k) % 2 == 0)
    cout << "YES";
  else
    cout << "NO";
}
