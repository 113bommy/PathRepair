#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 90000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000009;
  (a < 0) && (a += 1000000009);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000009, b %= 1000000009;
  normal(a), normal(b);
  return (a * b) % 1000000009;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000009, b %= 1000000009;
  normal(a), normal(b);
  return (a + b) % 1000000009;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000009, b %= 1000000009;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000009 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
set<pair<int, int> > exist;
set<pair<int, pair<int, int> > > valid;
map<int, map<int, int> > score;
int fuck[101000], fuckYou[101000];
bool canRemove(const pair<int, int> &a) {
  bool l = exist.find(pair<int, int>(a.first - 1, a.second)) != exist.end();
  bool l2 = exist.find(pair<int, int>(a.first - 2, a.second)) != exist.end();
  bool r = exist.find(pair<int, int>(a.first + 1, a.second)) != exist.end();
  bool r2 = exist.find(pair<int, int>(a.first + 2, a.second)) != exist.end();
  bool t = exist.find(pair<int, int>(a.first, a.second + 1)) != exist.end();
  bool tl =
      exist.find(pair<int, int>(a.first - 1, a.second + 1)) != exist.end();
  bool tr =
      exist.find(pair<int, int>(a.first + 1, a.second + 1)) != exist.end();
  if (t && !l && !r) return false;
  if (tl && !l && !l2) return false;
  if (tr && !r && !r2) return false;
  return true;
}
void op(const pair<int, int> &a) {
  if ((exist.find(pair<int, int>(a.first, a.second - 1)) != exist.end()) &&
      canRemove(pair<int, int>(a.first, a.second - 1)))
    valid.insert(pair<int, pair<int, int> >(
        score[a.first][a.second - 1], pair<int, int>(a.first, a.second - 1)));
  if ((exist.find(pair<int, int>(a.first - 1, a.second - 1)) != exist.end()) &&
      canRemove(pair<int, int>(a.first - 1, a.second - 1)))
    valid.insert(
        pair<int, pair<int, int> >(score[a.first - 1][a.second - 1],
                                   pair<int, int>(a.first - 1, a.second - 1)));
  if ((exist.find(pair<int, int>(a.first + 1, a.second - 1)) != exist.end()) &&
      canRemove(pair<int, int>(a.first + 1, a.second - 1)))
    valid.insert(
        pair<int, pair<int, int> >(score[a.first + 1][a.second - 1],
                                   pair<int, int>(a.first + 1, a.second - 1)));
  if ((exist.find(pair<int, int>(a.first + 1, a.second)) != exist.end()) &&
      !canRemove(pair<int, int>(a.first + 1, a.second)))
    valid.erase(pair<int, pair<int, int> >(
        score[a.first + 1][a.second], pair<int, int>(a.first + 1, a.second)));
  if ((exist.find(pair<int, int>(a.first + 2, a.second)) != exist.end()) &&
      !canRemove(pair<int, int>(a.first + 2, a.second)))
    valid.erase(pair<int, pair<int, int> >(
        score[a.first + 2][a.second], pair<int, int>(a.first + 2, a.second)));
  if ((exist.find(pair<int, int>(a.first - 1, a.second)) != exist.end()) &&
      !canRemove(pair<int, int>(a.first - 1, a.second)))
    valid.erase(pair<int, pair<int, int> >(
        score[a.first - 1][a.second], pair<int, int>(a.first - 1, a.second)));
  if ((exist.find(pair<int, int>(a.first - 2, a.second)) != exist.end()) &&
      !canRemove(pair<int, int>(a.first - 2, a.second)))
    valid.insert(pair<int, pair<int, int> >(
        score[a.first - 2][a.second], pair<int, int>(a.first - 2, a.second)));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> fuck[i] >> fuckYou[i];
    exist.insert(pair<int, int>(fuck[i], fuckYou[i]));
    score[fuck[i]][fuckYou[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    if (canRemove(pair<int, int>(fuck[i], fuckYou[i])))
      valid.insert(pair<int, pair<int, int> >(
          score[fuck[i]][fuckYou[i]], pair<int, int>(fuck[i], fuckYou[i])));
  }
  while (!exist.empty()) {
    static int turn = 0;
    if (turn) {
      auto it = *valid.begin();
      valid.erase(valid.begin());
      exist.erase(it.second);
      op(it.second);
      ans = modAdd(modMul(ans, n), it.first);
    } else {
      auto it = valid.end();
      --it;
      auto temp = it->second;
      int val = it->first;
      exist.erase(temp);
      valid.erase(it);
      op(temp);
      ans = modAdd(modMul(ans, n), val);
    }
    turn = 1 - turn;
  }
  cout << ans;
  return 0;
}
