#include <bits/stdc++.h>
using namespace std;
vector<string> parse(string s) {
  string a;
  vector<string> wyn;
  for (int i = 0; i < ((int)s.size()); ++i)
    if (s[i] != ' ')
      a += s[i];
    else if (!a.empty()) {
      wyn.push_back(a);
      a = "";
    }
  if (!a.empty()) wyn.push_back(a);
  return wyn;
}
const int INF = ~(1 << 31);
int get_digits(unsigned long long x) {
  int count = 0;
  while (x > 0) {
    x /= 10;
    count++;
  }
  return count;
}
unsigned long long get_wynik(unsigned long long x) {
  int digs = get_digits(x);
  int tab[digs];
  unsigned long long tmp = x;
  for (int i = 0; i <= (digs - 1); ++i) {
    tab[digs - i - 1] = tmp % 10;
    tmp /= 10;
    tab[digs - i - 1] = 9 - tab[digs - i - 1];
  }
  unsigned long long out = 0;
  bool check = 1;
  for (int i = 0; i <= (digs - 1); ++i) {
    if (tab[i] == 0 && check) {
      continue;
    } else
      check = 0;
    out *= 10;
    out += tab[i];
  }
  return out;
}
int main() {
  unsigned long long a, b;
  cin >> a >> b;
  int b_dig = get_digits(b);
  int a_dig = get_digits(a);
  if (b <= 5 * pow(10, b_dig - 1))
    a = get_wynik(b) * b;
  else if (a >= 5 * pow(10, a_dig - 1))
    a = get_wynik(a) * a;
  else {
    unsigned long long mm = 5 * pow(10, b_dig - 1);
    a = get_wynik(mm) * mm;
  }
  cout << a << endl;
  return 0;
}
