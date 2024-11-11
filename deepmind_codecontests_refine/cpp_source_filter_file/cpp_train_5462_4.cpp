#include <bits/stdc++.h>
using namespace std;
vector<long long int> factor(long long int n) {
  vector<long long int> tab;
  for (long long int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      tab.push_back(i);
      n /= i;
    }
  }
  if (n > 1) tab.push_back(n);
  return tab;
}
int main() {
  vector<long long int> v1, v2, v3, v4;
  long long int a, b, c, d;
  cin >> a >> b;
  cin >> c >> d;
  v1 = factor(a);
  v2 = factor(b);
  v3 = factor(c);
  v4 = factor(d);
  long long int count12, count13, count22, count23;
  count12 = count13 = count22 = count23 = 0;
  char s1[100], s2[100];
  int ii, jj;
  ii = 0;
  jj = 0;
  for (int i = 0; i < v1.size(); ++i) {
    if (v1[i] == 2)
      count12++;
    else if (v1[i] == 3)
      count13++;
    else {
      s1[ii] = (char)(v1[i] + 48);
      ii++;
    }
  }
  for (int i = 0; i < v2.size(); ++i) {
    if (v2[i] == 2)
      count12++;
    else if (v2[i] == 3)
      count13++;
    else {
      s1[ii] = (char)(v2[i] + 48);
      ii++;
    }
  }
  for (int i = 0; i < v3.size(); ++i) {
    if (v3[i] == 2)
      count22++;
    else if (v3[i] == 3)
      count23++;
    else {
      s2[jj] = (char)(v3[i] + 48);
      jj++;
    }
  }
  for (int i = 0; i < v4.size(); ++i) {
    if (v4[i] == 2)
      count22++;
    else if (v4[i] == 3)
      count23++;
    else {
      s2[jj] = (char)(v4[i] + 48);
      jj++;
    }
  }
  sort(s1, s1 + ii);
  sort(s2, s2 + jj);
  int flag = 0;
  if (ii != jj)
    flag = 1;
  else {
    for (int i = 0; i < ii; ++i) {
      if (s1[i] != s2[i]) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1) {
    cout << -1 << endl;
  } else {
    long long int count = 0;
    if (count13 > count23) {
      count = count13 - count23;
      long long int g = count;
      while (g != 0 && a % 3 == 0) {
        a /= 3;
        a *= 2;
        g--;
      }
      while (g != 0 && b % 3 == 0) {
        b /= 3;
        b *= 2;
        g--;
      }
      count12 += count13 - count23;
    } else if (count13 < count23) {
      count = count23 - count13;
      long long int g = count;
      while (g != 0 && c % 3 == 0) {
        c /= 3;
        c *= 2;
        g--;
      }
      while (g != 0 && d % 3 == 0) {
        d /= 3;
        d *= 2;
        g--;
      }
      count22 += count23 - count13;
    }
    if (count12 > count22) {
      long long int g = count12 - count22;
      while (g != 0 && a % 2 == 0) {
        a /= 2;
        g--;
      }
      while (g != 0 && b % 2 == 0) {
        b /= 2;
        g--;
      }
      count += count12 - count22;
    } else if (count13 < count23) {
      long long int g = count23 - count13;
      while (g != 0 && c % 2 == 0) {
        c /= 2;
        g--;
      }
      while (g != 0 && d % 2 == 0) {
        d /= 2;
        g--;
      }
      count += count22 - count12;
    }
    cout << count << endl;
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
  }
  return 0;
}
