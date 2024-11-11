#include <bits/stdc++.h>
int a, b, l, r;
char s[100];
int book[27];
using namespace std;
int main() {
  while (~scanf("%d%d%d%d", &a, &b, &l, &r)) {
    s[0] = '0';
    int k = 1;
    for (int i = 0; i < a; i++, k++) s[k] = 'a' + i;
    if (a > b) {
      s[k] = s[k + b - a];
      k++;
    } else {
      s[k] = a + 'a';
      k++;
    }
    for (int i = 1; i < b; i++, k++) s[k] = s[k - 1];
    memset(book, 0, sizeof(book));
    for (int i = b + 1; i < a + b + 1; i++) {
      book[s[i] - 'a'] = 1;
    }
    for (int i = 0; i < a; i++, k++) {
      for (int j = 0; j < 26; j++) {
        if (book[j] == 0) {
          s[k] = 'a' + j;
          book[j] = 1;
          break;
        }
      }
    }
    if (a > b) {
      s[k] = s[k + b - a];
      k++;
    } else {
      memset(book, 0, sizeof(book));
      for (int i = a + b + 1; i < a + a + b + 1; i++) {
        book[s[i] - 'a'] = 1;
      }
      for (int j = 0; j < 26; j++) {
        if (book[j] == 0) {
          s[k] = 'a' + j;
          k++;
          book[j] = 1;
          break;
        }
      }
    }
    for (int i = 1; i < b; i++, k++) s[k] = s[k - 1];
    for (int i = 1; i < 2 * (a + b) + 1; i++, k++) s[k] = s[i];
    s[k] = '\0';
    int len = r - l + 1;
    if (len >= 2 * a + 2 * b) len = 2 * a + 2 * b;
    int ll, rr;
    ll = (l - 1) % (2 * a + 2 * b) + 1;
    rr = ll + len;
    memset(book, 0, sizeof(book));
    int sum = 0;
    for (int i = ll; i < rr; i++) {
      if (book[s[i] - 'a'] == 0) {
        sum++;
        book[s[i] - 'a'] = 1;
      }
    }
    s[0] = '0';
    k = 1;
    for (int i = 0; i < a; i++, k++) s[k] = 'a' + i;
    for (int i = 0; i < b; i++, k++) s[k] = s[k - 1];
    memset(book, 0, sizeof(book));
    for (int i = b + 1; i < a + b + 1; i++) {
      book[s[i] - 'a'] = 1;
    }
    for (int i = 0; i < a; i++, k++) {
      for (int j = 0; j < 26; j++) {
        if (book[j] == 0) {
          s[k] = 'a' + j;
          book[j] = 1;
          break;
        }
      }
    }
    for (int i = 0; i < b; i++, k++) s[k] = s[k - 1];
    for (int i = 1; i < 2 * (a + b) + 1; i++, k++) s[k] = s[i];
    s[k] = '\0';
    len = r - l + 1;
    if (len >= 2 * a + 2 * b) len = 2 * a + 2 * b;
    ll = (l - 1) % (2 * a + 2 * b) + 1;
    rr = ll + len;
    memset(book, 0, sizeof(book));
    int ans = 0;
    for (int i = ll; i < rr; i++) {
      if (book[s[i] - 'a'] == 0) {
        ans++;
        book[s[i] - 'a'] = 1;
      }
    }
    if (sum < ans) ans = sum;
    printf("%d\n", ans);
  }
  return 0;
}
