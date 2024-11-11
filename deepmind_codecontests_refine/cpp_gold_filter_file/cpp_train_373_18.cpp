#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n, x;
char ord[9];
int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  while (n--) {
    scanf("%s", ord);
    if (ord[0] == 's') {
      long long z = 0LL;
      for (int i = 2; i < a.size(); i += 5) z += a[i];
      printf("%I64d\n", z);
    } else {
      scanf("%d", &x);
      if (ord[0] == 'a')
        a.insert(lower_bound(a.begin(), a.end(), x), x);
      else
        a.erase(lower_bound(a.begin(), a.end(), x));
    }
  }
  return 0;
}
