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
    if (!pmarked[i]) {
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
bool IsPermutation(const vector<int>& v, vector<int>& mark) {
  bool res = true;
  for (size_t i = 0; i < v.size(); ++i) {
    if (v[i] >= v.size()) {
      res = false;
      break;
    }
    if (mark[v[i]]) res = false;
    mark[v[i]] = 1;
  }
  for (size_t i = 0; i < v.size(); ++i) mark[i] = 0;
  return res;
}
void SolveB() {
  size_t n;
  cin >> n;
  vector<int> p0vs(n), vsb0(n);
  for (size_t i = 0; i < n; ++i) {
    cout << "? 0 " << i << "\n";
    cout.flush();
    cin >> p0vs[i];
    cout << "? " << i << " 0\n";
    cout.flush();
    cin >> vsb0[i];
  }
  vector<int> p(n), b(n), ans(n), mark(n, 0);
  size_t cnt = 0;
  for (size_t i = 0; i < n; ++i) {
    p[0] = i;
    for (size_t j = 0; j < n; ++j) {
      b[j] = p[0] ^ p0vs[j];
      p[j] = b[0] ^ vsb0[j];
    }
    bool ok = IsPermutation(p, mark) && IsPermutation(b, mark);
    if (ok) {
      for (size_t j = 0; j < n; ++j) ok = ok && (p[b[j]] == j);
    }
    if (ok) {
      ++cnt;
      for (size_t j = 0; j < n; ++j) ans[j] = p[j];
    }
  }
  cout << "!\n" << cnt << "\n";
  for (size_t i = 0; i < n; ++i) cout << ans[i] << " ";
  cout.flush();
}
size_t RangeSum(size_t i1, size_t i2, const vector<size_t>& v) {
  return v[i2] - v[i1 - 1];
}
void SolveD() {
  size_t n;
  cin >> n;
  vector<size_t> minDiv(n + 1, 0);
  for (size_t i = 2; i * i <= n; ++i) {
    if (minDiv[i]) continue;
    size_t cur = 2 * i;
    while (cur <= n) {
      if (minDiv[cur] == 0) minDiv[cur] = i;
      cur += i;
    }
  }
  vector<size_t> countPrimes(n + 1);
  for (size_t i = 2; i <= n; ++i) {
    countPrimes[i] = countPrimes[i - 1];
    if (minDiv[i] == 0) ++countPrimes[i];
  }
  vector<size_t> cnt(n + 1, 0);
  for (size_t i = 2; i <= n; ++i)
    if (minDiv[i] == 0)
      ++cnt[i];
    else
      ++cnt[minDiv[i]];
  for (size_t i = 2; i <= n; ++i) cnt[i] += cnt[i - 1];
  size_t numbits[256];
  for (size_t i = 0; i < 256; ++i) {
    int x = i;
    numbits[i] = 0;
    for (int j = 0; j < 8; ++j)
      if (x & (1 << j)) ++numbits[i];
  }
  vector<size_t> divs;
  unsigned long long ans = 0;
  for (size_t i = 2; i <= n; ++i) {
    size_t cur = i;
    divs.clear();
    while (cur != 1) {
      size_t d = minDiv[cur];
      if (d == 0) d = cur;
      if (divs.empty() || d != divs.back()) divs.push_back(d);
      cur = cur / d;
    }
    long long n1 = 0;
    int nd = divs.size();
    for (int j = 1; j < (1 << nd); ++j) {
      size_t x = 1;
      for (int k = 0; k < nd; ++k)
        if (j & (1 << k)) x *= divs[k];
      if (numbits[j] % 2)
        n1 += (n / x);
      else
        n1 -= (n / x);
    }
    if (2 * i > n && minDiv[i] == 0) continue;
    --n1;
    size_t md = divs[0];
    size_t n0 = RangeSum(1 + (n / 2), n, countPrimes);
    if (minDiv[i] != 0 || 2 * i <= n) ++n0;
    size_t n3 = 0;
    if (md > 2 && 2 * md <= n && (n / md) + 1 <= n / 2) {
      n3 = RangeSum((n / md) + 1, n / 2, cnt);
      if (md > (n / md)) n3 -= RangeSum(md, md, cnt);
    }
    size_t n2 = (n - 1) - n0 - n1 - n3;
    ans += n1 + 2 * n2 + 3 * n3;
  }
  cout << ans / 2;
}
int main(int argc, char** argv) {
  SolveD();
  return 0;
}
