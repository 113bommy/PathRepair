#include <bits/stdc++.h>
using namespace std;
int a[100005], p, len, gen, g;
string s, word, temp;
int main() {
  while (getline(cin, s) && s != "") {
    p = 0;
    istringstream in(s);
    a[0] = 1;
    bool flag = true, total = 0, tot = 0;
    gen = 0;
    g = 0;
    while (in >> word) {
      len = word.length();
      p++;
      a[p] = 0;
      if (len >= 3) {
        temp = word.substr(len - 3, 3);
        if (temp == "etr") {
          a[p] = 2;
          gen = 0;
        }
      }
      if (len >= 4) {
        temp = word.substr(len - 4, 4);
        if (temp == "lios") {
          a[p] = 1;
          gen = 0;
        }
        if (temp == "etra") {
          a[p] = 2;
          gen = 1;
        }
      }
      if (len >= 5) {
        temp = word.substr(len - 5, 5);
        if (temp == "liala") {
          a[p] = 1;
          gen = 1;
        }
      }
      if (len >= 6) {
        temp = word.substr(len - 6, 6);
        if (temp == "initis") {
          a[p] = 3;
          gen = 0;
        }
        if (temp == "inites") {
          a[p] = 3;
          gen = 1;
        }
      }
      if (a[p] == 2) total++;
      tot++;
      if (a[p] < a[p - 1]) {
        flag = false;
        break;
      }
      if (a[p] == 2 && a[p] == a[p - 1]) {
        flag = false;
        break;
      }
      if (p == 1)
        g = gen;
      else if (g != gen) {
        flag = false;
        break;
      }
    }
    if (tot == 1) {
      if (flag)
        puts("YES");
      else
        puts("NO");
    } else if (flag && total == 1)
      puts("YES");
    else
      puts("NO");
  }
}
