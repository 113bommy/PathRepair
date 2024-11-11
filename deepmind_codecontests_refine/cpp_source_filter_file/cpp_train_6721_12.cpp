#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
string to_str(T str) {
  stringstream stream;
  stream << str;
  return stream.str();
}
template <typename T>
int to_int(T num) {
  int val;
  stringstream stream;
  stream << num;
  stream >> val;
  return val;
}
vector<string> split(const string& s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) elems.push_back(item);
  return elems;
}
const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int T2 = 105;
const int T3 = 1005;
const int T4 = 10005;
const int T5 = 100005;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  int n;
  cin >> n;
  cin >> s;
  int cnt = 0;
  int ln = ((int)s.size());
  for (int i = 0; i < ln; i++) {
    if (s[i] == '>')
      cnt++;
    else
      break;
  }
  int cnt1 = 0;
  for (int i = ln - 1; i >= 0; i--) {
    if (s[i] == '<')
      cnt1++;
    else
      break;
  }
  cout << cnt + cnt1 << endl;
  return 0;
}
