#include <bits/stdc++.h>
using namespace std;
vector<int> pset[3];
void initSet(int N, int ind) {
  pset[ind].assign(N, 0);
  for (int i = 0; i < N; i++) pset[ind][i] = i;
}
int findSet(int i, int ind) {
  return (pset[ind][i] == i) ? i : (pset[ind][i] = findSet(pset[ind][i], ind));
}
bool isSameSet(int i, int j, int ind) {
  return findSet(i, ind) == findSet(j, ind);
}
void unionSet(int i, int j, int ind) {
  pset[ind][findSet(i, ind)] = findSet(j, ind);
}
void CompLeftDiags(vector<int>& res, vector<int>& heights) {
  int activediag = 0;
  int activecount = 0;
  heights.push_back(0);
  for (int i = 0; i < heights.size(); i++) {
    if (heights[i] >= i - activediag + 1)
      activecount++;
    else {
      while (heights[i] < i - activediag + 1) {
        if (activediag != heights.size() - 1) res[activediag] = activecount;
        activediag++;
        activecount--;
        if (activediag == i + 1) {
          activecount = 0;
        }
      }
      if (activediag != i + 1) i--;
    }
  }
  heights.pop_back();
}
int main() {
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++) cin >> heights[i];
  vector<int> leftdiag(n, 0);
  CompLeftDiags(leftdiag, heights);
  reverse(heights.begin(), heights.end());
  vector<int> rightdiag(n, 0);
  CompLeftDiags(rightdiag, heights);
  reverse(rightdiag.begin(), rightdiag.end());
  int max_surv = 0;
  for (int i = 0; i < n; i++) {
    int l = 0;
    int r = 100005;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (i - m >= 0 && i + m < n && leftdiag[i - m] >= m + 1 &&
          rightdiag[i + m] >= m + 1) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    max_surv = max(max_surv, l + 1);
  }
  cout << max_surv << endl;
  cin.get();
  cin.get();
  return 0;
}
