#include <bits/stdc++.h>
using namespace std;
const int DaysInAMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int N, M;
string Str;
vector<string> S;
inline int DayInAYear(int Month, int Day) {
  for (int i = 0; i < Month; i++) Day += DaysInAMonth[i];
  return Day;
}
vector<int> T;
int main(void) {
  cin.sync_with_stdio(0);
  cin >> N >> M;
  getline(cin, Str);
  while (!cin.eof()) {
    getline(cin, Str);
    S.push_back(Str);
    int Time = DayInAYear((Str[5] - '0') * 10 + Str[6] - '0' - 1,
                          (Str[8] - '0') * 10 + Str[9] - '0') *
                   24 * 60 * 60 +
               ((Str[11] - '0') * 10 + Str[12] - '0') * 60 * 60 +
               ((Str[14] - '0') * 10 + Str[15] - '0') * 60 +
               ((Str[17] - '0') * 10 + Str[18] - '0');
    T.push_back(Time);
  }
  int SizeT = T.size() - 1;
  for (int i = M - 1; i < SizeT; i++)
    if (T[i] - T[i - M + 1] < N) {
      for (int j = 0; j < 19; j++) cout << S[i][j];
      cout << endl;
      return 0;
    }
  cout << -1 << endl;
  return 0;
}
