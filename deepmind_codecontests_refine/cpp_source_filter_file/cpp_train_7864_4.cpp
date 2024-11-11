#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool up = 1;
  int arr[92];
  scanf("%d", &n);
  if (n == 1) {
    int a;
    scanf("%a", &a);
    if (a == 15)
      puts("DOWN");
    else if (a == 0)
      puts("UP");
    else
      puts("-1");
    return 0;
  }
  scanf("%d", &arr[0]);
  for (int i = 1; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  if (arr[n - 1] > arr[n - 2])
    up = 1;
  else
    up = 0;
  if (arr[n - 1] == 0)
    puts("UP");
  else if (arr[n - 1] == 15)
    puts("DOWN");
  else if (up)
    puts("UP");
  else
    puts("DOWN");
}
