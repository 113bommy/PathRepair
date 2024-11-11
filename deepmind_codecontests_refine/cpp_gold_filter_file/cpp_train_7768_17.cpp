#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  long long n, sum, a;
  cin >> n >> sum;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    sum -= a;
    if (i != n) sum--;
  }
  if (sum == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
