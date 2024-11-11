#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return a < 0 ? (-a) : a;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
T ToObject(const string &s) {
  istringstream iss(s);
  T res;
  iss >> res;
  return res;
}
const int DAYS[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long ToSeconds(const string &date, const string &time) {
  long long month = ToObject<int>(date.substr(5, 2));
  long long day = ToObject<int>(date.substr(8, 2));
  long long hour = ToObject<int>(time.substr(0, 2));
  long long minute = ToObject<int>(time.substr(3, 2));
  long long second = ToObject<int>(time.substr(6, 2));
  for (int(i) = 0; (i) < (month - 1); (i)++) day += DAYS[i];
  hour += 24 * day;
  minute += 60 * hour;
  second += 60 * minute;
  return second;
}
vector<long long> cs;
int main() {
  int n, m;
  cin >> n >> m;
  string s1, s2, st;
  while (cin >> s1 >> s2) {
    s2 = s2.substr(0, 8);
    getline(cin, st);
    cs.push_back(ToSeconds(s1, s2));
    if (cs.size() >= m && cs.back() - cs[cs.size() - m] < n) {
      cout << s1 << " " << s2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
