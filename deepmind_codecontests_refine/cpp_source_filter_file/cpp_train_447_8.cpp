#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[50][50];
  int i, j, n;
  int Sv, Sg = Sv = 0;
  int count = 0;
  cin >> n;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      cin >> A[i][j];
    }
  }
  vector<int> SumG;
  vector<int> SumV;
  i = j = 0;
  while (j < n) {
    Sv = 0;
    for (int i = 0; i < n; ++i) {
      Sv += A[i][j];
    }
    SumV.push_back(Sv);
    j++;
  }
  i = j = 0;
  while (i < n) {
    Sg = 0;
    for (int j = 0; j < n; ++j) {
      Sg += A[i][j];
    }
    SumG.push_back(Sg);
    i++;
  }
  vector<int>::iterator itg;
  vector<int>::iterator itv;
  for (itg = SumG.begin(); itg != SumG.end(); ++itg) {
    for (itv = SumV.begin(); itv != SumV.end(); ++itv) {
      if (*itv < *itg) count++;
    }
  }
  cout << count;
  char end;
  cin >> end;
  return 0;
}
