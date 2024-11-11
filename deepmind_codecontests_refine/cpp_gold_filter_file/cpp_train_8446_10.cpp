#include <bits/stdc++.h>
using namespace std;
string masc[3] = {"lios", "etr", "initis"};
string fem[3] = {"liala", "etra", "inites"};
string in[100005];
int n;
bool check1() {
  int ln = ((int)(masc[0]).size());
  int i = 0;
  while (((int)(in[i]).size()) >= ((int)(masc[0]).size()) && i < n &&
         in[i].substr(((int)(in[i]).size()) - ln, ln) == masc[0])
    i++;
  ln = ((int)(masc[1]).size());
  if (((int)(in[i]).size()) >= ((int)(masc[1]).size()) && i < n &&
      in[i].substr(((int)(in[i]).size()) - ln, ln) == masc[1])
    i++;
  else
    return false;
  ln = ((int)(masc[2]).size());
  while (((int)(in[i]).size()) >= ((int)(masc[2]).size()) && i < n &&
         in[i].substr(((int)(in[i]).size()) - ln, ln) == masc[2])
    i++;
  if (i != n) return false;
  return true;
}
bool check2() {
  int ln = ((int)(fem[0]).size());
  int i = 0;
  while (((int)(in[i]).size()) >= ((int)(fem[0]).size()) && i < n &&
         in[i].substr(((int)(in[i]).size()) - ln, ln) == fem[0])
    i++;
  ln = ((int)(fem[1]).size());
  if (((int)(in[i]).size()) >= ((int)(fem[1]).size()) && i < n &&
      in[i].substr(((int)(in[i]).size()) - ln, ln) == fem[1])
    i++;
  else
    return false;
  ln = ((int)(fem[2]).size());
  while (((int)(in[i]).size()) >= ((int)(fem[2]).size()) && i < n &&
         in[i].substr(((int)(in[i]).size()) - ln, ln) == fem[2])
    i++;
  if (i != n) return false;
  return true;
}
bool check() {
  if (n > 1) return false;
  for (int i = 0; i < 3; i++) {
    int ln = ((int)(masc[i]).size());
    if (((int)(in[0]).size()) >= ((int)(masc[i]).size()) &&
        in[0].substr(((int)(in[0]).size()) - ln, ln) == masc[i])
      return true;
  }
  for (int i = 0; i < 3; i++) {
    int ln = ((int)(fem[i]).size());
    if (((int)(in[0]).size()) >= ((int)(fem[i]).size()) &&
        in[0].substr(((int)(in[0]).size()) - ln, ln) == fem[i])
      return true;
  }
  return false;
}
int main() {
  string temp;
  while (cin >> temp) {
    in[n] = temp;
    n++;
  }
  if (check() || check1() || check2())
    cout << "YES\n";
  else
    cout << "NO\n";
}
