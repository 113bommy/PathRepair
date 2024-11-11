#include <bits/stdc++.h>
using namespace std;
const int NMAX = 51;
const long long MAX_LONG_LONG = 1LL << 62;
int Q;
long long a, b, m;
long long pow2[NMAX];
long long safeAdd(long long a, long long b) {
  if (a >= MAX_LONG_LONG - b) {
    return MAX_LONG_LONG;
  }
  return a + b;
}
long long safeMul(long long a, long long b) {
  if (a >= MAX_LONG_LONG / b) {
    return MAX_LONG_LONG;
  }
  return a * b;
}
long long fMin(int N, long long a) {
  return safeAdd(safeMul(pow2[N - 2], a), pow2[N - 2]);
}
long long fMax(int N, long long a) {
  return safeAdd(safeMul(pow2[N - 2], a), safeMul(pow2[N - 2], m));
}
bool solutionExists(int N, long long a, long long b) {
  return fMin(N, a) <= b && b <= fMax(N, a);
}
void recons(int N, long long a, long long b, vector<long long>& sol) {
  assert(N >= 2);
  assert(solutionExists(N, a, b));
  if (N <= 2) {
    sol.push_back(a);
    sol.push_back(b);
    return;
  }
  long long l = 1, r = m + 1;
  while (r - l > 1) {
    long long mid = l + (r - l) / 2;
    if (safeAdd(fMin(N - 1, a + mid), safeMul(pow2[N - 3], a)) > b) {
      r = mid;
    } else {
      l = mid;
    }
  }
  long long maxLeft = l;
  l = maxLeft - 1;
  r = m;
  while (r - l > 1) {
    long long mid = l + (r - l) / 2;
    if (safeAdd(fMax(N - 1, a + mid), safeMul(pow2[N - 3], a)) < b) {
      l = mid;
    } else {
      r = mid;
    }
  }
  long long minRight = r;
  assert(maxLeft <= minRight);
  sol.push_back(a);
  recons(N - 1, a + maxLeft, b - a * pow2[N - 3], sol);
}
int main() {
  pow2[0] = 1;
  for (int i = 1; i < NMAX; i++) {
    pow2[i] = pow2[i - 1] * 2;
  }
  cin >> Q;
  for (int query = 0; query < Q; query++) {
    cin >> a >> b >> m;
    if (a == b) {
      cout << "1 " << b << "\n";
      continue;
    }
    bool foundSol = false;
    vector<long long> sol;
    for (int N = 2; N <= 50 && !foundSol; N++) {
      if (solutionExists(N, a, b)) {
        cout << N;
        recons(N, a, b, sol);
        long long carry = 0;
        for (size_t i = 0; i < sol.size(); i++) {
          carry = carry * 2 + (i >= 2 ? sol[i - 2] : 0);
          cout << " " << sol[i] + carry;
        }
        cout << "\n";
        foundSol = true;
      }
    }
    if (!foundSol) {
      cout << "-1\n";
    }
  }
  return 0;
}
