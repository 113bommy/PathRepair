#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, rb, ra;
  bool good = false;
  string usr;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> usr >> rb >> ra;
    if (rb >= 2400 && ra > rb) {
      good = true;
    }
  }
  if (good)
    printf("YES\n");
  else {
    printf("NO\n");
  }
  return 0;
}
