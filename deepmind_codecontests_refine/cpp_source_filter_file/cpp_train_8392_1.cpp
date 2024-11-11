#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
int n, m, a[maxn], ji;
string s;
int transfrom(char s) {
  if (s >= 'a' && s <= 'z')
    return s - 'a';
  else if (s >= 'A' && s <= 'Z')
    return s - 'A' + 26;
  else
    return s - '0' + 52;
}
char reist(int s) {
  if (s >= 0 && s <= 25)
    return char('a' + s);
  else if (s >= 26 && s <= 51)
    return char('A' + s - 26);
  else
    return char(s - 52 + '0');
}
char find() {
  for (int i = 0; i <= 61; i++)
    if (a[i] >= 2) {
      a[i] -= 2;
      return reist(i);
    }
}
string my_reverse(string s) {
  string now = "";
  for (int i = s.length() - 1; i >= 0; i--) now += s[i];
  return now;
}
void run_even(int x) {
  cout << n / x << endl;
  for (int i = 1; i <= n / x; i++) {
    string s = "";
    for (int j = 1; j <= x / 2; j++) s += find();
    cout << s + my_reverse(s) << " ";
  }
  exit(0);
}
void run_odd(int x) {
  cout << n / x << endl;
  for (int i = 1; i <= n / x; i++) {
    string s = "", mid = "";
    for (int j = 1; j <= x / 2; j++) s += find();
    int flag = 0;
    for (int j = 0; j <= 61; j++)
      if (a[j] % 2 == 1 && !flag) mid += reist(j), a[j]--, flag = 1;
    for (int j = 0; j <= 61; j++)
      if (a[j] && !flag) mid += reist(j), a[j]--, flag = 1;
    cout << s + mid + my_reverse(s) << " ";
  }
  exit(0);
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < s.length(); i++) a[transfrom(s[i])]++;
  for (int i = 0; i <= 61; i++)
    if (a[i] % 2 == 1) ji++;
  if (ji == 0) run_even(n);
  for (int i = n; i >= 1; i--) {
    if (n % i != 0) continue;
    if (n % 2 == 0) continue;
    if (n / i < ji)
      continue;
    else {
      int s = n / i - ji;
      if (s % 2 == 1)
        continue;
      else
        run_odd(i);
    }
  }
}
