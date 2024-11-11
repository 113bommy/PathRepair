#include <bits/stdc++.h>
using namespace std;
bool flag = 0;
int GCD(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return GCD(a % b, b);
}
int main() {
  int n;
  scanf("%d", &n);
  int arr[100001];
  int i;
  int greatestdivisor = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    greatestdivisor = GCD(greatestdivisor, arr[i]);
  }
  bool flag = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] == greatestdivisor) flag = 1;
  }
  if (flag)
    printf("%d", greatestdivisor);
  else
    printf("-1");
}
