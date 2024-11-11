#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n * 2 == int(sqrt(n)) * (int(sqrt(n)) + 1))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
