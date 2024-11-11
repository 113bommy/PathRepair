#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
set<pair<int, int> > x_count;
long long int l_count = 0;
long long int r_count = 0;
void get_val(char x) {
  if (x == 'L') l_count++;
  if (x == 'R') l_count--;
  if (x == 'U') r_count++;
  if (x == 'D') r_count--;
}
void get_string(string s, char start, char end) {
  int i = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == start) {
      l_count = 0;
      r_count = 0;
      get_val(s[i]);
      bool flag = 1;
      for (int j = i + 1; j < s.length(); j++) {
        get_val(s[j]);
        if (s[j] == end) {
          flag = 0;
          if ((l_count == 0) && (r_count == 0)) x_count.insert(make_pair(i, j));
        }
      }
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  string inp = "URDL";
  for (int i = 0; i < inp.length(); i++)
    for (int j = 0; j < inp.length(); j++) get_string(s, inp[i], inp[j]);
  cout << x_count.size() << '\n';
  return 0;
}
