#include <bits/stdc++.h>
using namespace std;
int findK(int k, long long int s[], int start, int end) {
  if (start > end) return -1;
  if (k > s[start] && k <= s[start + 1]) {
    return start + 1;
  }
  int mid = start + (end - start) / 2;
  if (k > s[mid]) {
    return findK(k, s, mid, end);
  }
  if (k <= s[mid - 1]) {
    return findK(k, s, start, mid - 1);
  }
  return mid;
}
int getIthDigit(int x, int i) {
  string s = to_string(x);
  return s[i - 1] - '0';
}
int findK1(int toSearch, long long int f[], int x) {
  if (f[x] == toSearch) return x % 10;
  int flag = -1;
  int pow10 = 10;
  for (int i = 1; i <= 5; i++) {
    if (toSearch <= f[pow10 - 1]) {
      flag = i;
      break;
    }
    pow10 *= 10;
  }
  pow10 /= 10;
  int updatedSearch = toSearch - f[pow10 - 1];
  int y = (pow10 - 1) + (updatedSearch / flag);
  if (updatedSearch % flag == 0) return y % 10;
  return getIthDigit(y + 1, updatedSearch % flag);
}
int main() {
  long long int f[100000];
  long long int s[100000];
  f[0] = 0;
  s[0] = 0;
  int increment = 1;
  int pow10 = 10;
  for (int i = 1; i < 100000; i++) {
    if (i == pow10) {
      increment++;
      pow10 *= 10;
    }
    f[i] = f[i - 1] + increment;
    s[i] = s[i - 1] + f[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    int x = findK(k, s, 1, 100000 - 1);
    int k1 = k - s[x - 1];
    int y = findK1(k1, f, x);
    cout << y << endl;
  }
}
