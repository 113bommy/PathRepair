#include <bits/stdc++.h>
using namespace std;
long int LCM(int, int);
bool bigger(const char &, const char &, bool &);
int main() {
  long int n, _lcm;
  int lena, lenb;
  bool flag;
  string a, b;
  cin >> n >> a >> b;
  lena = a.length();
  lenb = b.length();
  _lcm = LCM(lena, lenb);
  long int suma = 0, sumb = 0, cnt = 0;
  int i(0), j(0);
  while (cnt < n && cnt < _lcm) {
    flag = false;
    if (bigger(a[i++], b[j++], flag))
      suma++;
    else if (!flag)
      sumb++;
    cnt++;
    if (i == lena) i = 0;
    if (j == lenb) j = 0;
  }
  long int t = n / _lcm;
  if (t == 0)
    cout << sumb << ' ' << suma << endl;
  else {
    suma *= t;
    sumb *= t;
    cnt = t * _lcm;
    i = j = 0;
    while (cnt < n) {
      flag = false;
      if (bigger(a[i++], b[j++], flag))
        suma++;
      else if (!flag)
        sumb++;
      cnt++;
      if (i > lena) i = 0;
      if (j > lenb) j = 0;
    }
    cout << sumb << ' ' << suma << endl;
  }
  return 0;
}
long int LCM(int a, int b) {
  if (a < b) {
    int temp = a;
    a = b;
    b = temp;
  }
  int k = a;
  while (a % b != 0) a += k;
  return a;
}
bool bigger(const char &a, const char &b, bool &f) {
  if (a == b) {
    f = true;
    return false;
  }
  switch (a) {
    case 'R':
      if (b == 'S') return true;
      if (b == 'P') return false;
      break;
    case 'S':
      if (b == 'R') return false;
      if (b == 'P') return true;
      break;
    case 'P':
      if (b == 'R') return true;
      if (b == 'S') return false;
  }
}
