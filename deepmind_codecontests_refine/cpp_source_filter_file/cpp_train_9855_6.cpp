#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int toi(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
string tos(int n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
bool isnumber(string s) {
  for (int i = 0; i < s.length(); ++i)
    if (!isdigit(s[i])) return false;
  return true;
}
vector<long long> x;
void gen(long long cur, int four, int seven) {
  if (cur > 1000000000L) return;
  if (four == seven) x.push_back(cur);
  gen(cur * 10 + 4, four + 1, seven);
  gen(cur * 10 + 7, four, seven + 1);
}
int main() {
  long long n;
  long i;
  gen(0, 0, 0);
  cin >> n;
  sort(x.begin(), x.end());
  ;
  for (i = 0; i < (int)(x.size()); i++) {
    if (x[i] >= n) {
      cout << x[i] << endl;
      break;
    }
  }
  return 0;
}
