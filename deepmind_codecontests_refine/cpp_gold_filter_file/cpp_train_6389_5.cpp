#include <bits/stdc++.h>
using namespace std;
int ZERO;
int n, m;
priority_queue<pair<int, int> > QX, QY;
vector<pair<int, int> > pom;
int R = 1;
int TreeX[500000], TreeY[500000];
int stateX[200011];
void insertX(int gdzie, int war) {
  gdzie += R;
  TreeX[gdzie] = war;
  while (gdzie / 2) {
    gdzie /= 2;
    TreeX[gdzie] = max(TreeX[gdzie * 2], TreeX[gdzie * 2 + 1]);
  }
}
void insertY(int gdzie, int war) {
  gdzie += R;
  TreeY[gdzie] = war;
  while (gdzie / 2) {
    gdzie /= 2;
    TreeY[gdzie] = max(TreeY[gdzie * 2], TreeY[gdzie * 2 + 1]);
  }
}
int queryX(int a, int b) {
  a += R;
  b += R;
  int wyn = max(TreeX[a], TreeX[b]);
  while (a / 2 != b / 2) {
    if (!(a % 2)) wyn = max(wyn, TreeX[a + 1]);
    if (b % 2) wyn = max(wyn, TreeX[b - 1]);
    a /= 2;
    b /= 2;
  }
  return wyn;
}
int queryY(int a, int b) {
  a += R;
  b += R;
  int wyn = max(TreeY[a], TreeY[b]);
  while (a / 2 != b / 2) {
    if (!(a % 2)) wyn = max(wyn, TreeY[a + 1]);
    if (b % 2) wyn = max(wyn, TreeY[b - 1]);
    a /= 2;
    b /= 2;
  }
  return wyn;
}
void add(int first, int second) {
  pom.clear();
  while (!QY.empty() && -QY.top().first < second) {
    pair<int, int> P = QY.top();
    swap(P.first, P.second);
    P.second = -P.second;
    insertX(P.first, 0);
    insertY(P.second, 0);
    QY.pop();
    if (stateX[P.first] == P.second) pom.push_back(P);
    stateX[P.first] = 0;
  }
  pom.push_back(make_pair(first, second));
  reverse(pom.begin(), pom.end());
  for (int i = 0; i < (int)pom.size(); ++i) {
    int W = queryX(pom[i].first, n) + 1;
    insertX(pom[i].first, W);
    insertY(pom[i].second, W);
    stateX[pom[i].first] = pom[i].second;
    QX.push(make_pair(-pom[i].first, pom[i].second));
    QY.push(make_pair(-pom[i].second, pom[i].first));
  }
}
void cut(int first) {
  pom.clear();
  while (first && !QX.empty()) {
    pair<int, int> P = QX.top();
    P.first = -P.first;
    insertX(P.first, 0);
    insertY(P.second, 0);
    QX.pop();
    if (stateX[P.first] == P.second) pom.push_back(P), first--;
    stateX[P.first] = 0;
  }
  insertX(pom.back().first, 0);
  insertY(pom.back().second, 0);
  pom.pop_back();
  reverse(pom.begin(), pom.end());
  for (int i = 0; i < (int)pom.size(); ++i) {
    int W = queryY(pom[i].second, ZERO + 9) + 1;
    insertX(pom[i].first, W);
    insertY(pom[i].second, W);
    stateX[pom[i].first] = pom[i].second;
    QX.push(make_pair(-pom[i].first, pom[i].second));
    QY.push(make_pair(-pom[i].second, pom[i].first));
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  ZERO = m + 10;
  while (R < ZERO || R < n) R <<= 1;
  for (int i = 0; i < m; ++i) {
    int xd;
    scanf("%d", &xd);
    if (xd == 1) {
      int first, second;
      scanf("%d%d", &first, &second);
      add(first, ZERO + second - i);
    } else {
      int first;
      scanf("%d", &first);
      cut(first);
    }
    printf("%d\n", queryX(1, n));
  }
  return 0;
}
