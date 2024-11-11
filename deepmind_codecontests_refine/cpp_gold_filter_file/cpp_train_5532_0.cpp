#include <bits/stdc++.h>
using namespace std;
long long n;
int cnt;
int main() {
  cin >> n;
  while (n > 0) {
    if (n % 10 == 4 || n % 10 == 7) cnt++;
    n = n / 10;
  }
  if (cnt == 4 || cnt == 7)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
