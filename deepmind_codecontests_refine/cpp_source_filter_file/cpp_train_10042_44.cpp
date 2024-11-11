#include <bits/stdc++.h>
using namespace std;
int i, j;
long long n;
string s;
bool flag = false;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    if (i * i + i / 2 == n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
