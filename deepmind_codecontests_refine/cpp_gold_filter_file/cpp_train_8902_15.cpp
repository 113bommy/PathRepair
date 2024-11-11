#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
const long double PI = acos(-1.0);
char d[MAX];
int l[MAX];
int w[MAX];
int pos;
int main() {
  long long n;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  long long i;
  for (i = 0; i < n; i++) cin >> d[i];
  for (i = 0; i < n; i++) cin >> l[i];
  while (w[pos] == 0) {
    w[pos] = 1;
    if (d[pos] == '>')
      pos += l[pos];
    else
      pos -= l[pos];
    if (pos < 0 || pos >= n) {
      cout << "FINITE"
           << "\n";
      return 0;
    }
  }
  cout << "INFINITE"
       << "\n";
  return 0;
}
