#include <bits/stdc++.h>
using namespace std;
struct Aim {
  double p;
  long long x, y, t;
  Aim(long long p1, long long p2, long long p3, double p4)
      : x(p1), y(p2), t(p3), p(p4){};
  friend bool operator<(Aim a1, Aim a2) { return a1.t < a2.t; }
};
int Days[13], Year, Month, Day;
string S, T;
bool ok(int d, int m, int y) {
  if (y == 0) return false;
  if (m == 0 || m > 12) return false;
  int leap = (y % 4 == 0 && m == 2) ? 1 : 0;
  if (d == 0 || d > Days[m] + leap) return false;
  if (Year > y + 18)
    return true;
  else if (Year < y - 18)
    return false;
  else if (Month > m)
    return true;
  else if (Month < m)
    return false;
  else if (Day > m)
    return true;
  else if (Day < m)
    return false;
  else
    return true;
}
int main() {
  Days[1] = 31;
  Days[2] = 28;
  Days[3] = 31;
  Days[4] = 30;
  Days[5] = 31;
  Days[6] = 30;
  Days[7] = 31;
  Days[8] = 31;
  Days[9] = 30;
  Days[10] = 31;
  Days[11] = 30;
  Days[12] = 31;
  cin >> S;
  Day = (S[0] - '0') * 10 + S[1] - '0';
  Month = (S[3] - '0') * 10 + S[4] - '0';
  Year = (S[6] - '0') * 10 + S[7] - '0';
  if (Year == 0) {
    cout << "NO";
    return 0;
  }
  cin >> T;
  vector<int> v;
  for (int i = 0; i < ((int)T.size()); i += 3)
    v.push_back((T[i] - '0') * 10 + T[i + 1] - '0');
  do {
    if (ok(v[0], v[1], v[2])) {
      cout << "YES";
      return 0;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << "NO";
}
