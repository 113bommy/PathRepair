#include <bits/stdc++.h>
using namespace std;
string a, b, s;
int lena, lenb, lens;
void remove_0() {
  string fia(""), fib(""), fis("");
  for (int i = 0; i < lena || i < lenb || i < lens; i++) {
    if (i < lena) {
      if (a[i] != '0') {
        fia += a[i];
      }
    }
    if (i < lenb) {
      if (b[i] != '0') {
        fib += b[i];
      }
    }
    if (i < lens) {
      if (s[i] != '0') {
        fis += s[i];
      }
    }
  }
  a = fia;
  b = fib;
  s = fis;
}
void a_b_s() {
  int carry = 0, j = lenb - 1;
  string fi("");
  for (int i = lena - 1; i > -1; i--) {
    int ev = (int)a[i] + carry - 48;
    if (j > -1) {
      ev += (int)b[j] - 48;
      j--;
    }
    if (ev > 9) {
      carry = 1;
    } else {
      carry = 0;
    }
    fi = (char)(ev % 10 + 48) + fi;
  }
  if (carry > 0) {
    fi = '1' + fi;
  }
  s = fi;
}
void change() {
  lena = a.size();
  lenb = b.size();
  if (lenb > lena) {
    string ts = a;
    int tlen = lena;
    a = b;
    b = a;
    lena = lenb;
    lenb = lena;
  }
}
int main() {
  cin >> a >> b;
  change();
  a_b_s();
  lens = s.size();
  remove_0();
  string tmp = s;
  change();
  a_b_s();
  cout << (s == tmp ? "YES" : "NO") << "\n";
  return 0;
}
