#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int sum = 0, rem = 0;
  scanf("%d", &t);
  vector<int> a(t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &a[i]);
    rem += a[i];
  }
  sort(a.begin(), a.end());
  int i = 0;
  while (sum <= rem) {
    sum += a[i];
    rem -= a[i];
    i++;
  }
  printf("%d\n", i);
  return 0;
}
