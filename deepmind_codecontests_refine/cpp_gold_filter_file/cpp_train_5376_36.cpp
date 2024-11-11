#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n > 33)
    cout << m;
  else
    cout << m % (1LL << n) << endl;
}
