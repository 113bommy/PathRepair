#include <bits/stdc++.h>
using namespace std;
int n, t;
int a[1001000];
bool close[1001000];
stack<int> open;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    close[i] = false;
  }
  scanf("%d", &t);
  int temp;
  for (int i = 0; i < t; i++) {
    scanf("%d", &temp);
    close[temp - 1] = true;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (close[i]) {
      open.push(a[i]);
    } else {
      if ((open.size() != 0) && (open.top() == a[i])) {
        open.pop();
      } else {
        close[i] = true;
        open.push(a[i]);
      }
    }
  }
  if (open.size() != 0) {
    printf("NO\n");
  } else {
    printf("YES\n");
    printf("%d", a[0]);
    for (int i = 1; i < n; i++) {
      if (close[i])
        printf(" %d", -a[i]);
      else
        printf(" %d", a[i]);
    }
    printf("\n");
  }
  return (0);
}
