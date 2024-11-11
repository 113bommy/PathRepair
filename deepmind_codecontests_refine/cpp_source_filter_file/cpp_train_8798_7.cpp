#include <bits/stdc++.h>
using namespace std;
map<string, bool> a;
int main() {
  int n;
  cin >> n;
  string z[200000];
  for (int i = 0; i < n; i++) cin >> z[i];
  for (int i = n - 1; i > 0; i--) {
    if (a[z[i]] == 0) {
      cout << z[i] << endl;
      a[z[i]] = 1;
    }
  }
  cin >> n;
}
