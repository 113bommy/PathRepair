#include <bits/stdc++.h>
using namespace std;
char s[100000];
long n;
long k;
long a[26];
char c1[26];
long b[26];
void qsort(int first, int last) {
  int i = first, j = last, x = a[(i + j) / 2];
  do {
    while (a[i] < x) {
      i++;
    }
    while (a[j] > x) {
      j--;
    }
    if (i <= j) {
      if (i != j) {
        swap(a[i], a[j]);
        swap(c1[i], c1[j]);
      }
      i++;
      j--;
    }
  } while (i <= j);
  if (i < last) {
    qsort(i, last);
  }
  if (j > first) {
    qsort(first, j);
  }
}
int main() {
  n = 0;
  char c;
  long i, j;
  for (i = 0; i < 26; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  while (scanf("%c", &c) == 1 && c != 10 && c != 13) {
    s[n] = c;
    a[c - 'a']++;
    n++;
  }
  cin >> k;
  long k1 = n - k;
  if (k1 < 0) {
    cout << "0\n";
    return 0;
  }
  if (k1 < 2) {
    cout << 1 << "\n";
    cout << s[0];
    return 0;
  }
  for (i = 0; i < 26; i++) {
    c1[i] = 'a' + i;
  }
  qsort(0, 25);
  i = 25;
  while (k1 > 0) {
    j = min(k1, a[i]);
    k1 -= j;
    b[c1[i] - 'a'] = j;
    i--;
  }
  cout << (25 - i) << "\n";
  for (i = 0; i < n; i++) {
    if (b[s[i] - 'a'] > 0) {
      cout << s[i];
      b[s[i] - 'a']--;
    }
  }
  return 0;
}
