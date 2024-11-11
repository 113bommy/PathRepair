#include <bits/stdc++.h>
using namespace std;
void SolveA() {
  size_t q;
  cin >> q;
  for (size_t i = 0; i < q; ++i) {
    size_t n;
    cin >> n;
    size_t res = 0;
    if ((n % 2)) {
      if (n < 9) {
        cout << "-1\n";
        continue;
      }
      n -= 9;
      ++res;
    }
    if (n % 4) {
      if (n < 6) {
        cout << "-1\n";
        continue;
      }
      n -= 6;
      ++res;
    }
    res += (n / 4);
    cout << res << "\n";
  }
}
void SolveC() {
  size_t n;
  cin >> n;
  vector<int> x(n), y(n), newX(n), newY(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  vector<size_t> ind(n);
  for (size_t i = 0; i < n; ++i) ind[i] = i;
  make_heap(ind.begin(), ind.end(),
            [&x](size_t i1, size_t i2) -> bool { return x[i1] < x[i2]; });
  sort_heap(ind.begin(), ind.end(),
            [&x](size_t i1, size_t i2) -> bool { return x[i1] < x[i2]; });
  newX[ind[0]] = 0;
  for (size_t i = 1; i < n; ++i)
    newX[ind[i]] = newX[ind[i - 1]] + ((x[ind[i]] == x[ind[i - 1]]) ? 0 : 1);
  for (size_t i = 0; i < n; ++i) ind[i] = i;
  make_heap(ind.begin(), ind.end(),
            [&y](size_t i1, size_t i2) -> bool { return y[i1] < y[i2]; });
  sort_heap(ind.begin(), ind.end(),
            [&y](size_t i1, size_t i2) -> bool { return y[i1] < y[i2]; });
  newY[ind[0]] = 0;
  for (size_t i = 1; i < n; ++i)
    newY[ind[i]] = newY[ind[i - 1]] + ((y[ind[i]] == y[ind[i - 1]]) ? 0 : 1);
  vector<size_t> xCnt(n, 0), xStart(n, 0), ix(n);
  for (size_t i = 0; i < n; ++i) ++xCnt[newX[i]];
  for (size_t i = 1; i < n; ++i) xStart[i] = xStart[i - 1] + xCnt[i - 1];
  xCnt.assign(n, 0);
  for (size_t i = 0; i < n; ++i) {
    ix[xStart[newX[i]] + xCnt[newX[i]]] = i;
    ++xCnt[newX[i]];
  }
  vector<size_t> yCnt(n, 0), yStart(n, 0), iy(n);
  for (size_t i = 0; i < n; ++i) ++yCnt[newY[i]];
  for (size_t i = 1; i < n; ++i) yStart[i] = yStart[i - 1] + yCnt[i - 1];
  yCnt.assign(n, 0);
  for (size_t i = 0; i < n; ++i) {
    iy[yStart[newY[i]] + yCnt[newY[i]]] = i;
    ++yCnt[newY[i]];
  }
  long long res = 1;
  const long long mod = 1000000007;
  vector<int> q;
  vector<int> xmarked(n, 0), ymarked(n, 0), pmarked(n, 0);
  for (size_t i = 0; i < n; ++i) {
    if (!pmarked[newX[i]]) {
      q.clear();
      size_t distinctCoords = 0;
      pmarked[i] = 1;
      q.push_back(i);
      for (size_t j = 0; j < q.size(); ++j) {
        size_t ic = q[j];
        int xc = newX[ic];
        int yc = newY[ic];
        if (!xmarked[xc]) {
          xmarked[xc] = 1;
          ++distinctCoords;
          for (size_t k = 0; k < xCnt[xc]; ++k) {
            size_t iNeib = ix[xStart[xc] + k];
            if (!pmarked[iNeib]) {
              q.push_back(iNeib);
              pmarked[iNeib] = 1;
            }
          }
        }
        if (!ymarked[yc]) {
          ymarked[yc] = 1;
          ++distinctCoords;
          for (size_t k = 0; k < yCnt[yc]; ++k) {
            size_t iNeib = iy[yStart[yc] + k];
            if (!pmarked[iNeib]) {
              q.push_back(iNeib);
              pmarked[iNeib] = 1;
            }
          }
        }
      }
      long long curMult = 1;
      for (size_t j = 0; j < distinctCoords; ++j) curMult = (curMult * 2) % mod;
      if (distinctCoords == q.size() + 1) curMult = (curMult + mod - 1) % mod;
      res = (res * curMult) % mod;
    }
  }
  cout << res;
}
int main(int argc, char **argv) {
  SolveC();
  return 0;
}
