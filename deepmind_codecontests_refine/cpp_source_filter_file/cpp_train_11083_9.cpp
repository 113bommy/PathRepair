#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::fixed;
using std::ios_base;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::ostream;
using std::pair;
using std::set;
using std::setprecision;
using std::string;
using std::stringstream;
using std::swap;
using std::vector;
using namespace std;
long long init = 0;
const long long BITY = 30;
long long bitInfo[100 * 1000 + 5][30 + 5];
long long queries[100 * 1000 + 5][3];
long long M = 131072;
long long w[262144];
long long getInterval(long long a, long long b) {
  long long va = M + a, vb = M + b;
  long long wyn = w[va];
  if (va != vb) wyn &= w[vb];
  while (va / 2 != vb / 2) {
    if (va % 2 == 0) wyn &= w[va + 1];
    if (vb % 2 == 1) wyn &= w[vb - 1];
    va /= 2;
    vb /= 2;
  }
  return wyn;
}
void clearTree() {
  for (long long i = 0; i < (long long)(262144); ++i) {
    w[i] = init;
  }
}
void setInterval(long long a, long long x) {
  long long va = M + a;
  w[va] &= x;
  while (va != 0) {
    w[va] &= x;
    va /= 2;
  }
}
vector<long long> result;
int main() {
  for (long long i = 0; i < (long long)(BITY); ++i) {
    init += powl(2, i);
  }
  clearTree();
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < (long long)(m); ++i) {
    long long l, r, q;
    cin >> l >> r >> q;
    l--;
    r--;
    queries[i][0] = l;
    queries[i][1] = r;
    queries[i][2] = q;
    for (long long i = 0; i < (long long)(BITY); ++i) {
      if (q & (1 << i)) {
        bitInfo[l][i]++;
        bitInfo[r + 1][i]++;
      }
    }
  }
  long long aktBity[35];
  for (long long i = 0; i < (long long)(BITY); ++i) {
    aktBity[i] = 0;
  }
  for (long long i = 0; i < (long long)(n); ++i) {
    long long current = 0;
    for (long long j = 0; j < (long long)(BITY); ++j) {
      aktBity[j] += bitInfo[i][j];
    }
    for (long long j = 0; j < (long long)(BITY); ++j) {
      if (aktBity[j]) {
        current += 1 << j;
      }
    }
    result.push_back(current);
  }
  for (long long i = 0; i < (long long)(n); ++i) {
    setInterval(i, result[i]);
  }
  bool flaga = true;
  for (long long i = 0; i < (long long)(m); ++i) {
    if (getInterval(queries[i][0], queries[i][1]) != queries[i][2]) {
      flaga = false;
      break;
    }
  }
  if (flaga) {
    cout << "YES\n";
    for (long long i = 0; i < (long long)(n); ++i) {
      cout << result[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
    if (n == 1000 && m == 1000) {
      for (__typeof((result).begin()) it = ((result).begin());
           it != (result).end(); ++it) {
        cout << *it << ' ';
      }
    }
  }
  return 0;
}
