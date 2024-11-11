#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x % 2) num++;
  }
  if (num)
    printf("First\n");
  else
    printf("Second\n");
  return 0;
}
