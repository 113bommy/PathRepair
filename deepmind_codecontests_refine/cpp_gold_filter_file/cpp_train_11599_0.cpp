#include <bits/stdc++.h>
using namespace std;
bool fun(long long n) {
  if (n == 1 || n == 14 || n == 144) return 1;
  if (n % 10 == 1 && fun(n / 10)) return 1;
  if (n % 100 == 14 && fun(n / 100)) return 1;
  if (n % 1000 == 144 && fun(n / 1000)) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  if (fun(n))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
