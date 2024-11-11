#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m, n;
  cin >> m >> n;
  int c;
  int temp = (m / 2) * n;
  if (m % 2 == 1) {
    c = (n / 2) * 1;
  }
  cout << temp + c << endl;
  return 0;
}
