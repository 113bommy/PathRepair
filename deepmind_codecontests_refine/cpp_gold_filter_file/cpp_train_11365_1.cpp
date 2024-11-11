#include <bits/stdc++.h>
using namespace std;
void f(int s, int m, string &c, string &a) {
  string temp = "0";
  for (int i = s, j = m - 1, k = 100000 - 1;; k--) {
    if (i < 0) {
      if ((int)(c[j] - '0') + stoi(temp) < 10)
        a = to_string((int)(c[j] - '0') + stoi(temp)) + a, temp = '0';
      else
        a = to_string((int)(c[j] - '0') + stoi(temp) - 10) + a, temp = '1';
      j--;
    } else if (j == s) {
      if ((int)(c[i] - '0') + stoi(temp) < 10)
        a = to_string((int)(c[i] - '0') + stoi(temp)) + a, temp = '0';
      else
        a = to_string((int)(c[i] - '0') + stoi(temp) - 10) + a, temp = '1';
      i--;
    } else {
      if ((int)(c[i] - '0') + (int)(c[j] - '0') + stoi(temp) < 10)
        a = to_string((int)(c[i] - '0') + (int)(c[j] - '0') + stoi(temp)) + a,
        temp = '0';
      else
        a = to_string((int)(c[i] - '0') + (int)(c[j] - '0') + stoi(temp) - 10) +
            a,
        temp = '1';
      i--, j--;
    }
    if (i < 0 && j == s) break;
  }
}
int main() {
  string c, a;
  int n;
  while (scanf("%d", &n, &c[0]) != EOF) {
    if (n < 10) {
      int m, temp, temp1, i = 10;
      scanf("%d", &m);
      while (m % 10 == 0) {
        if (m / (i / 10) % 10 != 0) break;
        i *= 10;
      }
      temp = m % i + m / i;
      for (i *= 10; m / i != 0; i *= 10) {
        if (m / (i / 10) % 10 != 0) {
          if (m / i + m % i < temp) temp = m / i + m % i;
        }
      }
      printf("%d\n", temp);
    } else {
      cin >> c;
      a = "";
      int m = c.size(), i = m / 2, j = m / 2 + 1;
      while (1) {
        if (i > 0 && c[i] != '0') {
          f(i - 1, m, c, a);
          break;
        }
        if (j < m && c[j] != '0') {
          f(j - 1, m, c, a);
          break;
        }
        i--, j++;
      }
      while (1) {
        int y = 1, z = 1;
        if (i == 0 && j == m) break;
        if (i > 0 && c[i] != '0') {
          string c1;
          f(i - 1, m, c, c1);
          if (c1.size() < a.size())
            a = c1, y = 0;
          else if (c1.size() == a.size() && a.compare(c1)) {
            int k = 0;
            while (k < a.size()) {
              if ((int)(a[k] - '0') != (int)(c1[k] - '0')) break;
              k++;
            }
            if (k != a.size() && (int)(a[k] - '0') > (int)(c1[k] - '0'))
              a = c1, y = 0;
          }
        }
        if (j < m && c[j] != '0') {
          string c1;
          f(j - 1, m, c, c1);
          if (c1.size() < a.size())
            a = c1, z = 0;
          else if (c1.size() == a.size() && a.compare(c1)) {
            int k = 0;
            while (k < a.size()) {
              if ((int)(a[k] - '0') != (int)(c1[k] - '0')) break;
              k++;
            }
            if (k != a.size() && (int)(a[k] - '0') > (int)(c1[k] - '0'))
              a = c1, z = 0;
          }
        }
        if (i > 0) i--;
        if (j < m) j++;
        if (y && z) break;
      }
      cout << a << endl;
    }
  }
  return 0;
}
