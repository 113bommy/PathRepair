#include <bits/stdc++.h>
using namespace std;
set<char> myset;
long long n, amount, a[1111111], ans, b[111];
string s;
void fun1();
void fun2();
void fun3();
void fun4();
void fun5();
void fun6();
void fun7();
int main() {
  fun2();
  return 0;
}
void fun1() {
  char ch = ' ';
  while (ch != '}') {
    cin >> ch;
    if (ch != '{' && ch != ' ' && ch != ',') myset.insert(ch);
  }
  cout << myset.size() - 1;
}
void fun2() {
  int y, ans = 0, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    a[x]++;
    b[y]++;
  }
  for (long long i = 0; i <= 100; i++) {
    if (a[i]) ans += a[i] * b[i];
  }
  cout << ans;
}
void fun3() {
  int x;
  cin >> n;
  int mx = -1, mn = 9999999999, numbermx, numbermn;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    if (mx < x) {
      numbermx = i;
      mx = x;
    }
    if (mn >= x) {
      numbermn = i;
      mn = x;
    }
  }
  if (numbermn < numbermx) {
    cout << numbermx + n - 2 - numbermn;
  } else {
    cout << numbermx + n - 1 - numbermn;
  }
}
void fun4() {
  char ch;
  long long ans1 = 0, ans2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ch;
    if (ch == 'D')
      ans1++;
    else
      ans2++;
  }
  if (ans1 == ans2)
    cout << "Friendship";
  else {
    if (ans1 > ans2)
      cout << "Danik";
    else
      cout << "Anton";
  }
}
void fun5() {
  long long x = 0, sumans = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
void fun6() {
  char ch;
  cin >> s;
  int n1 = s.length(), low = 0, up = 0, x = 0;
  for (int i = 0; i < n1; i++) {
    cin >> ch;
    if (s[i] == '0')
      low = 0;
    else
      low = 1;
    if (ch == '0')
      up = 0;
    else
      up = 1;
    if (low != up && low + up == 1)
      cout << 1;
    else
      cout << 0;
  }
}
void fun7() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  if (d == '9') {
    d = '0';
    if (c == '9') {
      c = '0';
      if (b == '9') {
        b = '0';
        a++;
      } else
        b++;
    } else
      c++;
  } else
    d++;
  for (; a <= '9'; a++) {
    for (; b <= '9'; b++) {
      for (; c <= '9'; c++) {
        for (; d <= '9'; d++) {
          if (a != b && a != c && a != d && b != c && b != d && c != d) {
            cout << a << b << c << d;
            return;
          }
        }
        d = '0';
      }
      c = '0';
    }
    b = '0';
  }
}
