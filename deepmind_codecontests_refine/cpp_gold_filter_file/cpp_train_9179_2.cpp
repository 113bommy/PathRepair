#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, c = 0;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 0; i < n; i += 2) {
    if (a[i] == 'a' && a[i + 1] == 'a') {
      a[i + 1] = 'b';
      c++;
    } else if (a[i] == 'b' && a[i + 1] == 'b') {
      a[i + 1] = 'a';
      c++;
    }
  }
  cout << c << endl;
  cout << a << endl;
}
