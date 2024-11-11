#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int MAXI = 0x7fffffff;
int in() {
  int x = 0, c;
  for (; (unsigned)((c = getchar()) - '0') >= 10;) {
    if (c == '-') return -in();
    if (!~c) throw ~0;
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned)((c = getchar()) - '0') < 10);
  return x;
}
vector<string> xml;
int cnt[1001];
void split(string s) {
  string tmp;
  for (int i = (0), _b = (s.size()); i < _b; i++) {
    tmp = "";
    if (s[i] == '<') {
      int j;
      j = i + 1;
      tmp += '<';
      while (s[j] != '>') {
        tmp += s[j];
        j++;
      }
      tmp += '>';
      xml.push_back(tmp);
    }
  }
}
int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  split(s);
  cnt[0] = 0;
  for (int i = (1), _b = (xml.size()); i < _b; i++) {
    if (xml[i][1] == '/') {
      if (xml[i - 1][1] == '/')
        cnt[i] = cnt[i - 1] - 1;
      else
        cnt[i] = cnt[i - 1];
    } else {
      if (xml[i - 1][1] == '/')
        cnt[i] = cnt[i - 1];
      else
        cnt[i] = cnt[i - 1] + 1;
    }
  }
  for (int i = (0), _b = (xml.size()); i < _b; i++) {
    for (int j = (0), _b = (2 * cnt[i]); j < _b; j++) cout << ' ';
    cout << xml[i] << endl;
  }
  return 0;
}
