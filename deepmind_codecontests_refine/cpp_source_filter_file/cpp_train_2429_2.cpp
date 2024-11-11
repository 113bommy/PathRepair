#include <bits/stdc++.h>
using namespace std;
int n, arr[107];
char str[107];
inline bool check1() {
  for (int i = 0; i < (n >> 1); ++i) {
    if (arr[i] >= arr[i + (n >> 1)]) return 0;
  }
  return 1;
}
inline bool check2() {
  for (int i = 0; i < (n >> 1); ++i) {
    if (arr[i] <= arr[i + (n >> 1)]) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  scanf("%s", str);
  n = strlen(str);
  for (int i = 0; i < n; ++i) arr[i] = (int)(str[i] - '0');
  sort(arr, arr + (n / 2));
  sort(arr + (n / 2), arr + n);
  puts((check1() || check2()) ? "YES" : "NO");
  return 0;
}
