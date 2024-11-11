#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
pair<string, string> rout[MAXN];
map<pair<string, string>, long long> totcos;
long long inicos[MAXN], a, b, c, d;
int n;
char s[MAXN];
string instr() {
  scanf("%s", s);
  string st = s;
  return st;
}
bool cmp(long long a, long long b) { return a > b; }
int main() {
  cin >> n >> a >> b >> c >> d;
  long long cost = 0;
  for (int i = 0; i < n; i++) {
    string st = instr(), en = instr();
    rout[i] = make_pair(st, en);
    if (i && st == rout[i - 1].second)
      cost += inicos[i] = b;
    else
      cost += inicos[i] = a;
    if (st > en) swap(st, en);
    if (totcos.count((make_pair(st, en))))
      totcos[make_pair(st, en)] += inicos[i];
    else
      totcos[make_pair(st, en)] = inicos[i];
  }
  long long _tcos[MAXN];
  int tn = 0;
  for (auto it : totcos) _tcos[tn++] = it.second;
  sort(_tcos, _tcos + tn, cmp);
  for (int i = 0; i < tn && i < c && _tcos[i] > d; i++) cost += d - _tcos[i];
  cout << cost << endl;
  return 0;
}
