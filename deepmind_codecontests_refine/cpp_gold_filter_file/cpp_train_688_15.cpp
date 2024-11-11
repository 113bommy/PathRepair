#include <bits/stdc++.h>
using namespace std;
const int MOD = 1E9 + 7;
int main() {
  string s = "                                                    ";
  int n;
  s += s + s + s + s + s + s + s + s + s + s;
  s += s;
  scanf("%d", &n);
  int arr[n + 2];
  arr[0] = 0, arr[1] = 1;
  for (int i = 2; i <= n + 1; ++i) arr[i] = arr[i - 1] + arr[i - 2];
  for (int i = 1; arr[i] <= n + 1; ++i) s[arr[i]] = 'O';
  for (int i = 1; i <= n; ++i) {
    if (!(s[i] - ' ')) s[i] = 'o';
    printf("%c", s[i]);
  }
  return 0;
}
