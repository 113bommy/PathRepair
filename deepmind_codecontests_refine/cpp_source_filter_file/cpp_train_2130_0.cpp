#include <bits/stdc++.h>
using namespace std;
int INT_MAX_VAL = (int)1e20;
int INT_MIN_VAL = (int)-1e20;
long long LONG_MAX_VAL = (long long)1e20;
long long LONG_MIN_VAL = (long long)-1e20;
int cb[8][3];
long long dist(int i, int j) {
  long long res = 0;
  for (long long(z) = 0LL; (z) < (3); (z)++) {
    res += (cb[i][z] - cb[j][z]) * (cb[i][z] - cb[j][z]);
  }
  return res;
}
bool perp(int a1, int a2, int i) {
  long long res = 0;
  for (long long(z) = 0LL; (z) < (3); (z)++) {
    res += (cb[a1][z] - cb[i][z]) * (cb[a2][z] - cb[i][z]);
  }
  return res == 0;
}
bool solve() {
  long long l = LONG_MAX_VAL;
  for (long long(i) = 0LL; (i) < (8); (i)++) {
    for (long long(j) = 0LL; (j) < (i - 1); (j)++) {
      l = min(l, dist(i, j));
    }
  }
  if (l == 0) return false;
  for (long long(i) = 0LL; (i) < (8); (i)++) {
    vector<int> ind;
    for (long long(j) = 0LL; (j) < (8); (j)++) {
      if (i == j) continue;
      if (l == dist(i, j)) {
        ind.push_back(j);
      }
    }
    if (ind.size() == 3) {
      if (!perp(ind[0], ind[1], i)) return false;
      if (!perp(ind[0], ind[2], i)) return false;
      if (!perp(ind[1], ind[2], i)) return false;
    } else {
      return false;
    }
  }
  return true;
}
bool perms(int i) {
  if (i == 8) {
    return solve();
  } else {
    for (long long(z) = 0LL; (z) < (3); (z)++) {
      if (perms(i + 1)) return true;
      swap(cb[i][1], cb[i][2]);
      if (perms(i + 1)) return true;
      swap(cb[i][0], cb[i][2]);
    }
  }
  return false;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  for (long long(i) = 0LL; (i) < (8); (i)++)
    for (long long(j) = 0LL; (j) < (3); (j)++) cin >> cb[i][j];
  if (perms(0)) {
    cout << "YES" << '\n';
    for (long long(i) = 0LL; (i) < (8); (i)++) {
      for (long long(j) = 0LL; (j) < (3); (j)++) cout << cb[i][j] << " ";
      cout << '\n';
    }
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
