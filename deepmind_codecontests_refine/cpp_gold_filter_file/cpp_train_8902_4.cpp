#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5 + 5;
int main() {
  int n, arr[SIZE], brr[SIZE], pos;
  string s;
  pos = 1;
  memset(brr, 0, sizeof(brr));
  brr[1] = 1;
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (s[pos - 1] == '>')
      pos += arr[pos - 1];
    else
      pos -= arr[pos - 1];
    if (pos < 1 || pos > n)
      return printf("FINITE") * 0;
    else if (brr[pos])
      return printf("INFINITE") * 0;
    else
      brr[pos] = 1;
  }
}
