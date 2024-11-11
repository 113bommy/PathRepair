#include <bits/stdc++.h>
using namespace std;
const int N = 120010;
map<int, int> c;
int a[N];
int main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    c[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    bool k = false;
    for (int j = 0; j < 29; j++) {
      int x = (1 << j) - a[i];
      if (c.count(x) && (c[x] > 1 || (c[x] == 1 && x != a[i]))) k = true;
    }
    if (!k) res++;
  }
  cout << res << endl;
  return 0;
}
