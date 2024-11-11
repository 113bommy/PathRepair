#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
bool isleap(int year) {
  if (year % 4 != 0) return false;
  if (year % 400 == 0) return true;
  if (year % 100 == 0) return false;
  return true;
}
int daysofmonth(int year, int month) {
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isleap(year) && month == 1)
    return 29;
  else
    return days[month];
}
int main() {
  istream &fin = cin;
  int YY, MM, DD, BY, BM, BD;
  string s;
  stringstream ss;
  getline(fin, s, '.');
  ss.str(s);
  ss >> DD;
  s.clear();
  ss.clear();
  ss.str("");
  getline(fin, s, '.');
  ss.str(s);
  ss >> MM;
  s.clear();
  ss.clear();
  ss.str("");
  getline(fin, s);
  ss.str(s);
  ss >> YY;
  s.clear();
  ss.clear();
  ss.str("");
  getline(fin, s, '.');
  ss.str(s);
  ss >> BD;
  s.clear();
  ss.clear();
  ss.str("");
  getline(fin, s, '.');
  ss.str(s);
  ss >> BM;
  s.clear();
  ss.clear();
  ss.str("");
  getline(fin, s);
  ss.str(s);
  ss >> BY;
  vector<int> vi(3);
  vi[0] = BY;
  vi[1] = BM;
  vi[2] = BD;
  sort(vi.begin(), vi.end());
  do {
    if (YY < vi[0] + 18) continue;
    if (vi[1] > 12 || vi[1] == 0) continue;
    int d = daysofmonth(vi[0], vi[1]);
    if (vi[2] > d || vi[2] == 0) continue;
    if (YY == vi[0] + 18 && MM < vi[1]) continue;
    if (YY == vi[0] + 18 && MM == vi[1] && DD < vi[2]) continue;
    cout << "YES" << endl;
    return 0;
  } while (next_permutation(vi.begin(), vi.end()));
  cout << "NO" << endl;
}
