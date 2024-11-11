#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, pair<int, int> > R1(pair<int, int>(2, 2),
                                         pair<int, int>(2, 2));
pair<pair<int, int>, pair<int, int> > R2(pair<int, int>(3, 4),
                                         pair<int, int>(3, 5));
int isInside(pair<pair<int, int>, pair<int, int> > A,
             pair<pair<int, int>, pair<int, int> > B) {
  return A.first.first <= B.first.first && B.second.first <= A.second.first &&
         A.first.second <= B.first.second && B.second.second <= A.second.second;
}
int count(pair<pair<int, int>, pair<int, int> > A) {
  pair<int, int> lo = A.first, hi = A.second;
  cout << "? " << lo.first << " " << lo.second << " " << hi.first << " "
       << hi.second << '\n';
  fflush(stdout);
  int ans;
  cin >> ans;
  return ans;
  return isInside(A, R1) + isInside(A, R2);
}
int n;
int f(int flagX, int flagY, int r) {
  pair<int, int> lo(1, 1), hi(n, n);
  if (flagX == 1) {
    hi.first = r;
  } else if (flagX == 2) {
    lo.first = n - r + 1;
  }
  if (flagY == 1) {
    hi.second = r;
  } else if (flagY == 2) {
    lo.second = n - r + 1;
  }
  return count(pair<pair<int, int>, pair<int, int> >(lo, hi));
}
vector<int> X, Y;
void insert(int flagX, int flagY, int r) {
  if (flagY == 0) {
    if (flagX == 1)
      X.push_back(r);
    else
      X.push_back(n - r);
  } else {
    if (flagY == 1)
      Y.push_back(r);
    else
      Y.push_back(n - r);
  }
}
int bSearch(int flagX, int flagY, int target) {
  int lo = 1, hi = n;
  if (f(flagX, flagY, lo) >= target) {
    insert(flagX, flagY, lo);
    return lo;
  }
  while (hi - lo > 1) {
    int med = (lo + hi) >> 1;
    if (f(flagX, flagY, med) >= target)
      hi = med;
    else
      lo = med;
  }
  insert(flagX, flagY, hi);
  return hi;
}
void fix(vector<int> &v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}
int Q[5][5][5][5];
int main() {
  while (cin >> n) {
    bSearch(1, 0, 1);
    bSearch(1, 0, 2);
    bSearch(2, 0, 1);
    bSearch(2, 0, 2);
    bSearch(0, 1, 1);
    bSearch(0, 1, 2);
    bSearch(0, 2, 1);
    bSearch(0, 2, 2);
    fix(X);
    fix(Y);
    for (int i2 = 0; i2 < ((int)X.size()); ++i2)
      for (int i1 = 0; i1 < i2; ++i1)
        for (int j2 = 0; j2 < ((int)Y.size()); ++j2)
          for (int j1 = 0; j1 < j2; ++j1) {
            pair<pair<int, int>, pair<int, int> > cur =
                pair<pair<int, int>, pair<int, int> >(
                    make_pair(X[i1] + 1, Y[j1] + 1), make_pair(X[i2], Y[j2]));
            Q[i2][i1][j1][j1] = (count(cur) == 1);
          }
    long long mini = LLONG_MAX;
    pair<pair<int, int>, pair<int, int> > rect1;
    for (int i2 = 0; i2 < ((int)X.size()); ++i2)
      for (int i1 = 0; i1 < i2; ++i1)
        for (int j2 = 0; j2 < ((int)Y.size()); ++j2)
          for (int j1 = 0; j1 < j2; ++j1) {
            pair<pair<int, int>, pair<int, int> > cur =
                pair<pair<int, int>, pair<int, int> >(
                    make_pair(X[i1] + 1, Y[j1] + 1), make_pair(X[i2], Y[j2]));
            if (Q[i2][i1][j1][j1]) {
              long long S =
                  (long long)(X[i2] - X[i1] + 2) * (Y[j2] - Y[j1] + 2);
              if (S < mini) {
                mini = S;
                rect1 = cur;
              }
            }
          }
    mini = LLONG_MAX;
    pair<pair<int, int>, pair<int, int> > rect2;
    for (int i2 = 0; i2 < ((int)X.size()); ++i2)
      for (int i1 = 0; i1 < i2; ++i1)
        for (int j2 = 0; j2 < ((int)Y.size()); ++j2)
          for (int j1 = 0; j1 < j2; ++j1) {
            pair<pair<int, int>, pair<int, int> > cur =
                pair<pair<int, int>, pair<int, int> >(
                    make_pair(X[i1] + 1, Y[j1] + 1), make_pair(X[i2], Y[j2]));
            if (Q[i2][i1][j1][j1]) {
              long long S = (long long)(X[i2] - X[i1]) * (Y[j2] - Y[j1]);
              if (S < mini && !isInside(cur, rect1)) {
                mini = S;
                rect2 = cur;
              }
            }
          }
    cout << "!";
    cout << " " << rect1.first.first << " " << rect1.first.second << " "
         << rect1.second.first << " " << rect1.second.second;
    cout << " " << rect2.first.first << " " << rect2.first.second << " "
         << rect2.second.first << " " << rect2.second.second;
    cout << "\n";
    fflush(stdout);
    return 0;
  }
}
