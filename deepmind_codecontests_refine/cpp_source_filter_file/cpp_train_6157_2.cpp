#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> del[1000100];
long long X1, X2, Y1, Y2, N;
string str;
void generateDel() {
  for (long long i = 0; i < N; i++) {
    del[i] = (i == 0 ? pair<long long, long long>(0, 0) : del[i - 1]);
    if (str[i] == 'U') {
      del[i].second++;
    } else if (str[i] == 'D') {
      del[i].second--;
    } else if (str[i] == 'R') {
      del[i].first++;
    } else {
      del[i].first--;
    }
  }
}
bool bisa(long long ans) {
  ans--;
  long long cyc = ans / N;
  long long mod = ans % N;
  pair<long long, long long> tot = {cyc * del[N - 1].first,
                                    cyc * del[N - 1].second};
  tot = {tot.first + del[mod].first, tot.second + del[mod].second};
  return abs(X2 - tot.first) + abs(Y2 - tot.second) <= ans + 1;
}
int main() {
  cin >> X1 >> Y1;
  cin >> X2 >> Y2;
  X2 -= X1;
  Y2 -= Y1;
  if (X2 == 0 && Y2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  cin >> N;
  cin >> str;
  N = str.length();
  generateDel();
  long long now = 0;
  long long MAXX = 1e15 + 5;
  for (long long i = 36; i > -1; i--) {
    long long tmpNow = now + (1LL << i);
    if (tmpNow > MAXX) continue;
    if (!bisa(tmpNow)) {
      now = tmpNow;
    }
  }
  cout << (now + 1 < MAXX ? now + 1 : -1) << endl;
  return 0;
}
