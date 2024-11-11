#include <bits/stdc++.h>
using namespace std;
const int inf((1 << 31) - 1);
int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
int n;
unsigned long long a1[2050][100] = {0};
unsigned long long a2[2050][100] = {0};
void setNum(int j, int i) {
  int ja = j / 64, jb = j % 64;
  a1[i][ja] |= 1 << jb;
  int ia = i / 64, ib = i % 64;
  a2[j][ia] |= 1 << ib;
}
int getNum(int j, int i) {
  unsigned long long out = 0;
  int k;
  for (k = 0; k < 33; k++) {
    out |= (a1[i][k] & a2[j][k]);
    if (out) return 1;
  }
  return 0;
}
int main() {
  bool visited[2500][2500] = {0};
  ios_base::sync_with_stdio(0);
  int n, j, i, L, Counter = 0;
  vector<pair<int, int> > zeros;
  cin >> n;
  for (j = 0; j < n; j++) {
    for (i = 0; i < n; i++) {
      cin >> L;
      if (L) {
        setNum(j, i);
      } else {
        zeros.push_back(pair<int, int>(j, i));
      }
    }
  }
  random_shuffle(zeros.begin(), zeros.end());
  bool Hope = true;
  while (Hope && zeros.size() != Counter) {
    Hope = false;
    for (auto IT : zeros) {
      if (visited[IT.first][IT.second]) continue;
      if (getNum(IT.first, IT.second)) {
        Hope = true;
        setNum(IT.first, IT.second);
        Counter++;
        visited[IT.first][IT.second] = 1;
      }
    }
  }
  if (Counter == zeros.size())
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
