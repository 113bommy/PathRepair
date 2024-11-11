#include <bits/stdc++.h>
using namespace std;
int x[1000001];
int main() {
  map<int, int> a;
  map<int, int>::iterator it;
  int n, A, k = 0, na = 1;
  scanf("%d%d", &n, &A);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    if (x[i] == A && k != 0) {
      na++;
      it = a.begin();
      while (it != a.end()) {
        if (it->second < na)
          it = a.erase(it);
        else
          it++;
      }
    } else if (x[i] == A && k == 0) {
      if (i == 0) {
        printf("-1\n");
        return 0;
      }
      k = i;
      for (int j = 0; j < i; j++) {
        if (a.count(x[j]))
          a[x[j]]++;
        else
          a.insert(pair<int, int>(x[j], 1));
      }
    } else if (k != 0 && a.count(x[i]))
      a[x[i]]++;
  }
  if (k == 0) {
    printf("%d\n", x[0]);
    return 0;
  }
  if (a.begin() == a.end())
    printf("-1\n");
  else
    printf("%d\n", a.begin()->second);
  return 0;
}
