#include <bits/stdc++.h>
using namespace std;
const double epsilon = 0.0000000001;
const int mod = 1000000007;
double pi = 2 * acos(0.0);
vector<int> del;
vector<int> V[1];
vector<int> K[1];
bool flag[1];
int w[1];
int xe, y;
int gcd(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
int gcd(long long a, long long b) { return a % b == 0 ? b : gcd(b % a, a); }
long long cnt, ans;
void DFS(int U) {
  int i;
  if (flag[U]) return;
  flag[U] = true;
  cnt++;
  ans += w[U];
  for (i = 0; i < V[U].size(); i++) DFS(V[U][i]);
}
long long soch(long long n, long long k) {
  int s = n % mod;
  for (int i = n - 1; i >= n - k + 1; i--) s = (s * i) % mod;
  for (int i = 2; i <= k; i++) {
    gcd(i, mod, xe, y);
    s *= (xe % mod + mod) % mod;
  }
  return s % mod;
}
int yo = -1;
int A[200100], B[200100];
char C[200100];
bool ff;
int nine(int k) {
  for (int i = k + 1; i <= yo; i++) A[i] = 0;
  while (A[k] == 9) A[k--] = 0;
  A[k]++;
  if (k == -1) ff = true;
  if (k < yo) k = yo - 1;
  return k;
}
int main() {
  int n, t;
  cin >> n >> t;
  char c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c == '.') {
      yo = i;
      continue;
    }
    if (yo == -1)
      A[i] = c - 48;
    else
      A[i - 1] = c - 48;
  }
  if (yo == -1) yo = n++;
  n--;
  int beg = -1, en = -1;
  for (int i = yo - 1; i < n - 1; i++) {
    if (A[i] == 4 && A[i + 1] == 4) {
      B[i] = 4;
    }
    if (A[i] == 4 && A[i + 1] < 4 && i > 0) {
      int j = i - 1;
      while (B[j] == 4) {
        B[j] = 0;
        j--;
      }
    }
    if (A[i + 1] > 4) {
      B[i] = 1;
    }
    if (A[i] == 4 && A[i + 1] > 4) {
      B[i] = 4;
    }
  }
  for (int i = yo - 1; i < n; i++) {
    if (B[i] > 0) {
      beg = 1;
      if (B[i] == 4) {
        int j = i;
        while (B[j] == 4) j++;
        j--;
        while (t > 0 && B[j] == 4 && j >= yo) {
          A[j]++;
          t--;
          j--;
        }
        if (t > 0)
          en = nine(j);
        else
          en = j + 1;
      } else {
        if (t > 0)
          en = nine(i);
        else
          en = n - 1;
      }
      break;
    }
  }
  if (ff) {
    cout << 1;
    for (int i = 0; i < yo; i++) cout << 0;
    return 0;
  }
  if (en == -1) {
    for (int i = 0; i < n; i++) {
      if (i == yo) cout << '.';
      cout << A[i];
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (i == yo && i <= en) cout << '.';
    if (i <= en)
      cout << A[i];
    else
      return 0;
  }
  return 0;
}
