#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.);
const long long INF = 1000 * 1000 * 1000 + 1;
const long long MOD = 1000 * 1000 * 1000 + 7;
vector<int> resp(15);
int bin1(int n, int prev, string& s) {
  int l = 0, r = n, cur, cntPrev = 0;
  while (r - l > 1) {
    int mid = l + (r - l) / 2;
    string cp(s);
    int cnt = 0;
    for (int i = l; i < mid; ++i) {
      cp[i] = '1';
      ++cnt;
    }
    cout << "? " << cp << endl;
    fflush(stdout);
    cin >> cur;
    if (cur - prev == cnt) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
int bin0(int n, int prev, string& s) {
  int l = 0, r = n, cur;
  while (r - l > 1) {
    int mid = l + (r - l) / 2;
    string cp(s);
    int cnt = 0;
    for (int i = l; i < mid; ++i) {
      cp[i] = '1';
      ++cnt;
    }
    cout << "? " << cp << endl;
    fflush(stdout);
    cin >> cur;
    if (prev - cur == cnt) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
int main() {
  int n;
  cin >> n;
  string guess(n, '0');
  cout << "? " << guess << endl;
  fflush(stdout);
  cin >> resp[0];
  guess[0] = '1';
  cout << "? " << guess << endl;
  fflush(stdout);
  cin >> resp[1];
  vector<int> pos(2, -1);
  int need;
  if (resp[1] > resp[0]) {
    pos[0] = 0;
    guess[0] = '0';
    pos[1] = bin1(n, resp[0], guess);
  } else {
    pos[1] = 0;
    guess[0] = '0';
    pos[0] = bin0(n, resp[0], guess);
  }
  cout << "! " << pos[0] + 1 << "  " << pos[1] + 1 << endl;
  fflush(stdout);
  return 0;
}
