#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const long long LINF = INF * (long long)INF;
const int MAX = 4007;
const int MOD = 998244353;
const double Pi = acos(-1.0);
int res[MAX];
int ids[MAX];
int main(int argc, char* argv[]) {
  int t;
  cin >> t;
  for (int tt = (0); tt < (t); tt++) {
    string a;
    string b;
    cin >> a >> b;
    int n = (int)a.size() / 2;
    vector<int> A(2 * n), B(2 * n);
    for (int i = (0); i < (2 * n); i++) {
      A[i] = a[i] - '0';
      B[i] = b[i] - '0';
    }
    int SA[3];
    int SB[3];
    for (int i = (0); i < (3); i++) SA[i] = SB[i] = 0;
    for (int i = (0); i < (n); i++) {
      SA[A[2 * i] + A[2 * i + 1]]++;
      SB[B[2 * i] + B[2 * i + 1]]++;
    }
    bool ok = true;
    for (int i = (0); i < (3); i++) ok &= (SA[i] == SB[i]);
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    while (true) {
      int m = 0;
      int k = 2 * n;
      while (k > 0) {
        if (m > 2 * n + 1) {
          break;
        }
        if (A[k - 2] == B[k - 2] && A[k - 1] == B[k - 1]) {
          k -= 2;
          continue;
        }
        if (A[0] == B[k - 1] && A[1] == B[k - 2]) {
          res[m++] = k;
          for (int i = (0); i < (k / 2); i++) swap(A[i], A[k - 1 - i]);
          k -= 2;
          continue;
        }
        if (A[0] == B[k - 2] && A[1] == B[k - 1]) {
          res[m++] = 2;
          swap(A[0], A[1]);
          res[m++] = k;
          for (int i = (0); i < (k / 2); i++) swap(A[i], A[k - 1 - i]);
          k -= 2;
          continue;
        }
        int c = 0;
        for (int i = 0; i < k; i += 2) {
          if (A[i] == B[k - 2] && A[i + 1] == B[k - 1]) {
            ids[c++] = i;
          }
        }
        if (c > 0) {
          int id = ids[rand() % c];
          res[m++] = id + 2;
          for (int i = (0); i < ((id + 2) / 2); i++) {
            swap(A[i], A[id + 2 - i - 1]);
          }
          res[m++] = k;
          for (int i = (0); i < (k / 2); i++) {
            swap(A[i], A[k - i - 1]);
          }
          k -= 2;
          continue;
        }
        for (int i = 0; i < k; i += 2) {
          if (A[i] == B[k - 1] && A[i + 1] == B[k - 2]) {
            ids[c++] = i;
          }
        }
        int id = ids[rand() % c];
        res[m++] = id + 2;
        for (int i = (0); i < ((id + 2) / 2); i++) {
          swap(A[i], A[id + 2 - i - 1]);
        }
        res[m++] = 2;
        swap(A[0], A[1]);
        res[m++] = k;
        for (int i = (0); i < (k / 2); i++) {
          swap(A[i], A[k - i - 1]);
        }
        k -= 2;
        continue;
      }
      if (m <= 2 * n + 1) {
        cout << m << endl;
        for (int i = (0); i < (m); i++) {
          cout << res[i] << ' ';
        }
        cout << endl;
        break;
      }
    }
  }
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
}
