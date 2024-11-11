#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
int main() {
  istream &fin = cin;
  ostream &fout = cout;
  FILE *fpin = stdin;
  FILE *fpout = stdout;
  int n;
  fin >> n;
  if (n == 1) {
    fout << "a" << endl;
    fout << "a" << endl;
    fout << "b" << endl;
    fout << "b" << endl;
    return 0;
  }
  if (n == 2) {
    fout << "aa" << endl;
    fout << "bb" << endl;
    fout << "cc" << endl;
    fout << "dd" << endl;
    return 0;
  }
  string res[4];
  res[0].push_back('a');
  res[1].push_back('b');
  res[2].push_back('e');
  res[3].push_back('e');
  char cur1 = 'a', cur2 = 'c';
  for (int i = 2; i < n; i += 2) {
    res[0].push_back(cur1);
    res[1].push_back(cur1 + 1);
    res[2].push_back(cur2);
    res[3].push_back(cur2 + 1);
    res[0].push_back((cur1 + 4) >= 'a' + 8 ? (cur1 + 4 - 8) : (cur1 + 4));
    res[1].push_back((cur1 + 5) >= 'a' + 8 ? (cur1 + 5 - 8) : (cur1 + 5));
    res[2].push_back(cur2);
    res[3].push_back(cur2 + 1);
    cur1 = ((cur1 + 4) >= 'a' + 8 ? (cur1 + 4 - 8) : (cur1 + 4));
    cur2 = ((cur2 + 4) >= 'a' + 8 ? (cur2 + 4 - 8) : (cur2 + 4));
  }
  if (n % 2 == 1) {
    res[0].push_back(cur1);
    res[1].push_back(cur1 + 1);
    res[2].push_back(cur2);
    res[3].push_back(cur2 + 1);
    res[0].push_back('z');
    res[1].push_back('z');
    res[2].push_back(cur2);
    res[3].push_back(cur2 + 1);
  } else {
    res[0].push_back(cur1);
    res[1].push_back(cur1 + 1);
    res[2].push_back('z');
    res[3].push_back('z');
  }
  for (int i = 0; i < 4; i++) {
    fout << res[i] << endl;
  }
}
