#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, l;
  cin >> s >> l;
  int szs = s.length();
  int szl = l.length();
  int as[10] = {0};
  int al[10] = {0};
  for (int i = 0; i < szs; i++) {
    if (s[i] == '6' || s[i] == '9')
      as[6]++;
    else if (s[i] == '2' || s[i] == '5')
      as[2]++;
    else if (s[i] == '1')
      as[1]++;
    else if (s[i] == '0')
      as[0]++;
    else if (s[i] == '3')
      as[3]++;
    else if (s[i] == '4')
      as[4]++;
    else if (s[i] == '7')
      as[7]++;
    else if (s[i] == '8')
      as[8]++;
  }
  for (int i = 0; i < szl; i++) {
    if (l[i] == '6' || l[i] == '9')
      al[6]++;
    else if (l[i] == '2' || l[i] == '5')
      al[2]++;
    else if (l[i] == '1')
      al[1]++;
    else if (l[i] == '0')
      al[0]++;
    else if (l[i] == '3')
      al[3]++;
    else if (l[i] == '4')
      al[4]++;
    else if (l[i] == '7')
      al[7]++;
    else if (l[i] == '8')
      al[8]++;
  }
  for (int i = 0; i < 10; i++) {
    if (as[i] == 0)
      al[i] = 10001;
    else
      al[i] = al[i] / as[i];
  }
  int mi = 100000;
  for (int i = 0; i < 10; i++) {
    if (al[i] < mi) mi = al[i];
  }
  cout << mi;
}
