#include <bits/stdc++.h>
using namespace std;
void ini() {}
int main() {
  ini();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  if (n == 1 and m == 1) {
  } else if (n % 2 == 0) {
    n /= 2;
    if (m < n) {
      n = m + 1;
    } else if (m > n) {
      n = m - 1;
    } else {
      n++;
    }
  } else {
    n /= 2;
    n++;
    if (m < n) {
      n = m + 1;
    } else if (m > n) {
      n = m - 1;
    } else {
      n--;
    }
  }
  cout << n;
}
