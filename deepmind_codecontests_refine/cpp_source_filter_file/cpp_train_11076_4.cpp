#include <bits/stdc++.h>
using namespace std;
int BS(int ar[], int siz, int b) {
  int left = 0, right = siz - 1, mid;
  while (left != right) {
    mid = left + (right - left) / 2;
    if (ar[mid] <= b)
      left = mid + 1;
    else
      right = mid;
  }
  return right;
}
int main() {
  string s;
  cin >> s;
  int ar[1000000], l = 0, m = 0;
  int ar1[1000000];
  for (int i = 0; i < s.size() - 1; i++) {
    if (i == s.size() - 4) break;
    if (s[i] == 'h' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'v' &&
        s[i + 4] == 'y') {
      ar[l] = i;
      l++;
    }
    if (s[i] == 'm' && s[i + 1] == 'e' && s[i + 2] == 't' && s[i + 3] == 'a' &&
        s[i + 4] == 'l') {
      ar1[m] = i;
      m++;
    }
  }
  int sum = 0;
  if (m == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < l; i++) {
    if (ar[i] > ar1[m - 1]) {
    } else
      sum += m - BS(ar1, m, ar[i]);
  }
  cout << sum;
}
