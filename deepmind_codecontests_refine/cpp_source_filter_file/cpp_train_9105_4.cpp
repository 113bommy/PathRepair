#include <bits/stdc++.h>
using namespace std;
inline int circRight(int a, unsigned m) {
  return (a >> m) | (a << (CHAR_BIT - m));
}
inline int circLeft(int a, unsigned m) {
  return (a << m) | (a >> (CHAR_BIT - m));
}
const long long MOD = 1000000009;
const int MAX_SIZE = 1e5 + 10;
int X[MAX_SIZE], Y[MAX_SIZE];
map<pair<int, int>, int> M;
set<int> S;
vector<int> V;
int findIdx(int x, int y) {
  if (M.find(make_pair(x, y)) != M.end()) return M[make_pair(x, y)];
  return -1;
}
int countCubesBelow(int i) {
  int val = 0;
  for (int j = -1; j <= 1; ++j) {
    if (findIdx(X[i] + j, Y[i] - 1) != -1) val++;
  }
  return val;
}
int idxOK(int i) {
  for (int j = -1; j <= 1; ++j) {
    int k = findIdx(X[i] + j, Y[i] + 1);
    if (k != -1 && countCubesBelow(k) == 1) return 0;
  }
  return 1;
}
void update(int i) {
  S.erase(i);
  M.erase(make_pair(X[i], Y[i]));
  for (int j = -1; j <= 1; ++j) {
    int idx = findIdx(X[i] + j, Y[i] - 1);
    if (idx != -1 && idxOK(idx)) {
      S.insert(idx);
    }
  }
  for (int j = -2; j <= 2; ++j) {
    int idx = findIdx(X[i] + j, Y[i]);
    if (idx != -1 && !idxOK(idx)) {
      S.erase(idx);
    }
  }
}
int main() {
  int m, x, y;
  long long answer = 0;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> X[i] >> Y[i];
    M.insert(make_pair(make_pair(X[i], Y[i]), i));
  }
  for (auto &iter : M) {
    if (idxOK(iter.second)) {
      S.insert(iter.second);
    }
  }
  for (int i = 0; i < m; ++i) {
    int key, front;
    set<int>::iterator it;
    set<int>::reverse_iterator rit;
    if (i % 2) {
      it = S.begin();
      V.push_back(*it);
      update(*it);
    } else {
      rit = S.rbegin();
      V.push_back(*rit);
      update(*rit);
    }
  }
  int t = 0;
  long long p = 1;
  for (int i = (int)V.size() - 1; i >= 0; --i) {
    answer += (V[i] * p) % MOD;
    p = (p * m) % MOD;
  }
  cout << answer << endl;
  return 0;
}
