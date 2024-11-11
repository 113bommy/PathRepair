#include <bits/stdc++.h>
using namespace std;
long long int c;
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<char> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int i;
  c = (n - k) / 2;
  if (c != 0) {
    for (i = 0; i < n - 1; i++) {
      if (a[i] == '(' && a[i + 1] == ')') {
        a.erase(a.begin() + i);
        a.erase(a.begin() + i);
        c--;
        i = i - 2;
      }
      if (c == 0) break;
    }
  }
  for (int j = 0; j < a.size(); j++) cout << a[j];
}
