#include <bits/stdc++.h>
using namespace std;
int ab[1000000];
int ab1[1000000];
int v1[1000000];
int v2[1000000];
set<int> l;
char ch[3];
char ch2[3];
map<unsigned long long int, unsigned long long int> m;
map<unsigned long long int, unsigned long long int> m1;
map<unsigned long long int, unsigned long long int> m2;
int main() {
  string s3, s1;
  int a, b, d = 10000000, j = 0, i = 0, t, s = 0, s2, as, as1, n = 50, c = 0,
            c1 = 0, e = 0, i1, k = 0, di = 0, se = 0, x;
  cin >> a;
  getline(cin, s1);
  getline(cin, s3);
  for (i = 0; i < a; i++) {
    if (s3[i] != '.' && c1 != 1) {
      c = i;
      c1 = 1;
    }
    if (c1 == 1 && s3[c + 1] == 'R') {
      if (s3[i] == 'L') {
        cout << c + 1 << ' ' << i << endl;
        return 0;
      } else if (s3[i] == '.') {
        cout << c + 1 << ' ' << i + 1 << endl;
        return 0;
      }
    } else if (c1 == 1 && s3[c + 1] == 'L') {
      if (s3[i] == '.') {
        cout << i << ' ' << c << endl;
        return 0;
      } else if (i == a - 1) {
        cout << i + 1 << ' ' << c << endl;
        return 0;
      }
    }
  }
}
