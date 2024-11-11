#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int days = 0, second, d, p;
  scanf("%d %d", &second, &d);
  days = second;
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &second, &d);
    p = second;
    while (p <= days) {
      p += d;
    }
    days = p;
  }
  cout << days;
  return 0;
}
