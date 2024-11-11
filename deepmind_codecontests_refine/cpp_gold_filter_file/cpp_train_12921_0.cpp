#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  int fre[N] = {0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    fre[a[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  int ed = 0;
  for (int i = 0; i < n; i++) {
    int id = fre[b[i]];
    if (id > ed) {
      cout << id - ed << " ";
      ed = id;
    } else
      cout << 0 << " ";
  }
  return 0;
}
