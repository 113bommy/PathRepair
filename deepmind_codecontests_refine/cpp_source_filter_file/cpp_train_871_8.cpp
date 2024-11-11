#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N];
int n, o, c, res;
int mex(set<int> &s) {
  int k = 0;
  for (int i : s) {
    if (i != k) return k;
    k++;
  }
  return s.size();
}
map<int, int> grundy;
int getGrundy(int x) {
  if (!x) return 0;
  if (grundy.count(x)) return grundy[x];
  set<int> to;
  for (int i = 0; i < 30; i++)
    if (x & (1 << i)) {
      int now = x;
      for (int j = i; j < 30; j += i + 1) now = now & (~(1 << j));
      to.insert(getGrundy(now));
    }
  grundy[x] = mex(to);
  return grundy[x];
}
void precalc() {
  vector<int> res;
  int mask = 0;
  for (int i = 0; i < 30; mask += (1 << i), i++) res.push_back(getGrundy(mask));
  cout << "int gr[]={";
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << ",}"[i == res.size() - 1];
  cout << endl;
}
int gr[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5,
            9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
int main() {
  cin >> n;
  o = n;
  for (long long i = 2; i * i < N; i++)
    if (!(c = vis[i])) {
      for (long long j = i; j <= n; j *= i, c++, o--)
        if (j < N) vis[j] = 1;
      res = res ^ gr[c];
    }
  if (res ^ (o & 1))
    cout << "Vasya" << endl;
  else
    cout << "Petya" << endl;
}
