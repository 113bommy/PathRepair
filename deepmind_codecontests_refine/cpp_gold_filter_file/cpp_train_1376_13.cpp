#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, m, t;
int v[MAXN];
char s[MAXN];
int main() {
  cin >> t;
  while (t--) {
    cin >> s + 1;
    n = strlen(s + 1);
    if (strcmp(s + n - 1, "po") == 0)
      cout << "FILIPINO";
    else if (strcmp(s + n - 3, "desu") == 0 || strcmp(s + n - 3, "masu") == 0)
      cout << "JAPANESE";
    else
      cout << "KOREAN";
    cout << endl;
  }
}
