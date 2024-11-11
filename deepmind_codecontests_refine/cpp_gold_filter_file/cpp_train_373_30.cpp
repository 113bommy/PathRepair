#include <bits/stdc++.h>
using namespace std;
int n, i, j, x;
long long sum;
char s[30];
vector<int> a;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", s);
    if (s[0] == 's') {
      sum = 0;
      for (j = 2; j < a.size(); j += 5) {
        sum += a[j];
      }
      cout << sum;
      printf("\n");
    } else {
      scanf("%d", &x);
      if (s[0] == 'a')
        a.insert(lower_bound(a.begin(), a.end(), x), x);
      else
        a.erase(lower_bound(a.begin(), a.end(), x));
    }
  }
  return 0;
}
