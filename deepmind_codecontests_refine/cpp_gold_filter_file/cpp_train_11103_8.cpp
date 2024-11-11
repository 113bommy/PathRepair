#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char a[maxn];
int main() {
  int n;
  cin >> n >> a;
  int len = strlen(a);
  for (int i = 1; i < len; ++i) {
    if ((a[i - 1] == 'R' && a[i] == 'U') || (a[i - 1] == 'U' && a[i] == 'R')) {
      i++;
      n--;
    }
  }
  cout << n << endl;
}
