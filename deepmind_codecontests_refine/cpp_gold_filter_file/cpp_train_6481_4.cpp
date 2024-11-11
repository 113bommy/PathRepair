#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int t, n;
int a[N];
int main() {
  cin >> t;
  while (t--) {
    int c = 0, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 1)
        c++;
      else
        k = i;
    }
    if (c == n)
      puts(c & 1 ? "First" : "Second");
    else
      puts(k & 1 ? "Second" : "First");
  }
}
