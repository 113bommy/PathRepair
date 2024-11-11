#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long res = 4 * (n - 1);
  while (n != 2) {
    res *= 3;
    n--;
  }
  cout << res;
}
