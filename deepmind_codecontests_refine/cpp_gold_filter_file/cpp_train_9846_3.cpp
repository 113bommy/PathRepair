#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long m = 0;
  long long s = 0;
  long long b[100];
  scanf("%d", &n);
  if (n != 1) {
    for (int i = 0; i < n; i++) {
      long long a = 0;
      scanf("%d", &a);
      b[i] = a;
      m = max(a, m);
    }
    for (int i = 0; i < n; i++) {
      s += m - b[i];
    }
    cout << s << endl;
  } else
    printf("0");
  return 0;
}
