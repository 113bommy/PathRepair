#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
const int MAX = (2e5) + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> makeArrayForQuery(int n) {
  vector<int> per(n);
  for (int i = 0; i <= n - 1; i++) {
    per[i] = i;
  }
  shuffle(per.begin(), per.end(), rng);
  return per;
}
map<pair<int, int>, int> mopa;
int giveAns(int x, int y) {
  if (x < y) {
    swap(x, y);
  }
  if (mopa.find({x, y}) != mopa.end()) {
    return mopa[{x, y}];
  }
  cout << "? " << x + 1 << " " << y + 1 << endl;
  int ret;
  cin >> ret;
  return mopa[{x, y}] = ret;
}
int n, know[MAX];
int findPos(int p) {
  int ret = 2047, co = min(n, 15);
  vector<int> posi = makeArrayForQuery(n);
  posi.resize(co);
  for (int c : posi)
    if (c != p) ret = (ret & giveAns(c, p));
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  memset(know, -1, sizeof(know));
  cin >> n;
  vector<int> chao = makeArrayForQuery(n);
  int p = chao[0];
  int x = findPos(p);
  know[p] = x;
  for (int i = 1; i <= n - 1; i++) {
    if (giveAns(p, chao[i]) == x) {
      p = chao[i];
      x = findPos(p);
      know[p] = x;
    }
    if (x == 0) {
      break;
    }
  }
  for (int i = 0; i <= n - 1; i++) {
    if (know[i] == -1) {
      know[i] = giveAns(i, p);
    }
  }
  cout << "! ";
  for (int i = 0; i <= n - 1; i++) {
    cout << know[i] << " ";
  }
  cout << endl;
  return 0;
}
