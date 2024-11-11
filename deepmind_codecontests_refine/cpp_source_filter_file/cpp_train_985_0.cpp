#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class A, class B, class C>
struct Triple {
  A first;
  B second;
  C third;
};
template <class T>
void ResizeVec(T&, vector<long long>) {}
template <class T>
void ResizeVec(vector<T>& vec, vector<long long> sz) {
  vec.resize(sz[0]);
  sz.erase(sz.begin());
  if (sz.empty()) {
    return;
  }
  for (T& v : vec) {
    ResizeVec(v, sz);
  }
}
inline bool leq(long long a1, long long a2, long long b1, long long b2) {
  return (a1 < b1 || a1 == b1 && a2 <= b2);
}
inline bool leq(long long a1, long long a2, long long a3, long long b1,
                long long b2, long long b3) {
  return (a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
}
static void radixPass(long long* a, long long* b, long long* r, long long n,
                      long long K) {
  long long* c = new long long[K + 1];
  for (long long i = 0; i <= K; i++) c[i] = 0;
  for (long long i = 0; i < n; i++) c[r[a[i]]]++;
  for (long long i = 0, sum = 0; i <= K; i++) {
    long long t = c[i];
    c[i] = sum;
    sum += t;
  }
  for (long long i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i];
  delete[] c;
}
void suffixArray(long long* s, long long* SA, long long n, long long K) {
  long long n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
  long long* s12 = new long long[n02 + 3];
  s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
  long long* SA12 = new long long[n02 + 3];
  SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
  long long* s0 = new long long[n0];
  long long* SA0 = new long long[n0];
  for (long long i = 0, j = 0; i < n + (n0 - n1); i++)
    if (i % 3 != 0) s12[j++] = i;
  radixPass(s12, SA12, s + 2, n02, K);
  radixPass(SA12, s12, s + 1, n02, K);
  radixPass(s12, SA12, s, n02, K);
  long long name = 0, c0 = -1, c1 = -1, c2 = -1;
  for (long long i = 0; i < n02; i++) {
    if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
      name++;
      c0 = s[SA12[i]];
      c1 = s[SA12[i] + 1];
      c2 = s[SA12[i] + 2];
    }
    if (SA12[i] % 3 == 1)
      s12[SA12[i] / 3] = name;
    else
      s12[SA12[i] / 3 + n0] = name;
  }
  if (name < n02) {
    suffixArray(s12, SA12, n02, name);
    for (long long i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
  } else
    for (long long i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
  for (long long i = 0, j = 0; i < n02; i++)
    if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
  radixPass(s0, SA0, s, n0, K);
  for (long long p = 0, t = n0 - n1, k = 0; k < n; k++) {
    long long i = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    long long j = SA0[p];
    if (SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3])
                     : leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j],
                           s[j + 1], s12[j / 3 + n0])) {
      SA[k] = i;
      t++;
      if (t == n02)
        for (k++; p < n0; p++, k++) SA[k] = SA0[p];
    } else {
      SA[k] = j;
      p++;
      if (p == n0)
        for (k++; t < n02; t++, k++)
          SA[k] = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    }
  }
  delete[] s12;
  delete[] SA12;
  delete[] SA0;
  delete[] s0;
}
const long long N = 2e6 + 5;
long long s[N];
long long SA[N];
vector<long long> MinK(vector<long long> vec, long long k) {
  vector<long long> res;
  long long n = ((long long)(vec).size());
  if (n - k + 1 <= 0) {
    return vector<long long>();
  }
  res.resize(n - k + 1);
  vector<long long> que;
  long long beg;
  for (long long i = 0; i < ((long long)(vec).size()); i++) {
    while (!que.empty() && vec[que.back()] >= vec[i]) {
      que.pop_back();
    }
    que.push_back(i);
    beg = min(beg, ((long long)(que).size()) - 1);
    if (que[beg] <= i - k) {
      beg++;
    }
    if (i >= k - 1) {
      res[i - k + 1] = vec[que[beg]];
    }
  }
  for (long long i = (1); i <= (k - 1); ++i) {
    res.push_back(N);
  }
  return res;
}
long long SAinv[N];
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  string br;
  cin >> br;
  ;
  long long n = ((long long)(br).size());
  br = ' ' + br;
  for (long long i = (1); i <= (n); ++i) {
    if (br[i] == '(') {
      s[i] = 1;
    } else {
      s[i] = 2;
    }
  }
  vector<long long> bilv(2 * n + 5);
  bilv.push_back(0);
  for (long long i = (n + 1); i <= (2 * n); ++i) {
    s[i] = s[i - n];
    br += br[i - n];
  }
  long long b = 0;
  for (long long i = (1); i <= (2 * n); ++i) {
    if (s[i] == 1) {
      b++;
    } else {
      b--;
    }
    bilv[i] = b;
  }
  long long bil = bilv[n];
  suffixArray(s + 1, SA + 1, 2 * n, 2);
  for (long long i = (1); i <= (2 * n); ++i) {
    SAinv[SA[i] + 1] = i;
  }
  vector<long long> mins = MinK(bilv, n);
  ;
  ;
  ;
  long long best = 0;
  SAinv[0] = N;
  for (long long i = (0); i <= (n - 1); ++i) {
    if (mins[i + 1] >= bilv[i] - min(0ll, bil)) {
      if (SAinv[i + 1] < SAinv[best]) {
        ;
        best = i + 1;
      }
    }
  }
  if (0) cout << "SAinv:\n";
  for (long long i = (1); i <= (n); ++i) {
    if (0) cout << SAinv[i] << " ";
  }
  if (0) cout << "\n";
  ;
  if (bil < 0) {
    for (long long i = (1); i <= (-bil); ++i) {
      cout << '(';
    }
  }
  for (long long i = (best); i <= (best + n - 1); ++i) {
    cout << br[i];
  }
  if (bil >= 0) {
    for (long long i = (1); i <= (bil); ++i) {
      cout << ')';
    }
  }
  cout << "\n";
  return 0;
}
