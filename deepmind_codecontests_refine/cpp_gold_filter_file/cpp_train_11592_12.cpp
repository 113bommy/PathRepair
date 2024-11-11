#include <bits/stdc++.h>
using namespace std;
const int maxn = 4;
long long a[maxn * maxn + 5];
int n;
struct State {
  long long b[4][4];
  bool ok() {
    int i, j;
    long long sum, sum1 = 0, sum2 = 0;
    for (i = 0; i < (int)(n); ++i) {
      sum1 += b[i][i];
      sum2 += b[i][n - i - 1];
    }
    if (sum1 != sum2) return false;
    sum = sum1;
    for (i = 0; i < (int)(n); ++i) {
      sum1 = sum2 = 0;
      for (j = 0; j < (int)(n); ++j) {
        sum1 += b[i][j];
        sum2 += b[j][i];
      }
      if (sum1 != sum || sum2 != sum) return false;
    }
    return true;
  }
};
void print(const State &s) {
  long long sum = 0, s1, s2;
  int i, j;
  s2 = 0;
  for (i = 0; i < (int)(n); ++i) {
    sum += s.b[i][i];
  }
  cout << sum << "\n";
  for (i = 0; i < (int)(n); ++i) {
    for (j = 0; j < (int)(n); ++j) cout << s.b[i][j] << " ";
    cout << "\n";
  }
  exit(0);
}
bool used[20];
long long sum, sum2, diag;
unsigned long long total, lft;
State st;
long long FIRST;
const int posX[] = {2, 3, 1, 3, 1, 2};
const int posY[] = {1, 1, 2, 2, 3, 3};
const int MAX_IT = 20;
void rec3(int k) {
  int i, j;
  if (k == 4) {
    if (diag != sum) return;
    j = 0;
    for (i = 0; i < (int)(16); ++i) {
      if (!used[i]) {
        st.b[posY[j]][posX[j]] = a[i];
        ++j;
        if (j == 6) break;
      }
    }
    for (int it = 0; it < MAX_IT; ++it) {
      if (st.ok()) {
        print(st);
      }
      int i1 = rand() % 6, i2 = rand() % 6;
      swap(st.b[posY[i1]][posX[i1]], st.b[posY[i2]][posX[i2]]);
    }
    return;
  }
  for (i = 0; i < (int)(16); ++i) {
    if (!used[i]) {
      used[i] = true;
      st.b[k][k] = a[i];
      diag += a[i];
      rec3(k + 1);
      diag -= a[i];
      used[i] = false;
    }
  }
}
void rec2(int y) {
  int i;
  if (y == 4) {
    if (sum2 != sum) return;
    diag = FIRST;
    rec3(1);
    return;
  }
  for (i = 0; i < (int)(16); ++i) {
    if (!used[i]) {
      used[i] = true;
      st.b[y][0] = a[i];
      sum2 += a[i];
      lft += a[i];
      rec2(y + 1);
      lft -= a[i];
      sum2 -= a[i];
      used[i] = false;
    }
  }
}
void rec(int x) {
  int i;
  if (x == 4) {
    if (total != 4 * (unsigned long long)sum) return;
    sum2 = FIRST;
    lft = 0;
    rec2(1);
    return;
  }
  for (i = 0; i < (int)(16); ++i) {
    if (!used[i]) {
      used[i] = true;
      st.b[0][x] = a[i];
      sum += a[i];
      rec(x + 1);
      sum -= a[i];
      used[i] = false;
    }
  }
}
int main() {
  srand(31415);
  ios::sync_with_stdio(false);
  int i, j, k;
  cin >> n;
  for (i = 0; i < (int)(n * n); ++i) {
    cin >> a[i];
    total += a[i];
  }
  if (n <= 3) {
    long long s1, s2;
    State st;
    vector<int> p(n * n);
    for (i = 0; i < (int)(n * n); ++i) p[i] = i;
    do {
      s1 = s2 = 0;
      k = 0;
      for (i = 0; i < (int)(n); ++i) {
        for (j = 0; j < (int)(n); ++j) {
          st.b[i][j] = a[p[k++]];
        }
      }
      if (st.ok()) {
        print(st);
        return 0;
      }
    } while (next_permutation(p.begin(), p.end()));
    return 0;
  }
  for (i = 0; i < (int)(16); ++i) {
    sum = FIRST = st.b[0][0] = a[i];
    used[i] = true;
    for (j = i + 1; j < 16; ++j) {
      st.b[0][1] = a[j];
      used[j] = true;
      sum += a[j];
      rec(2);
      sum -= a[j];
      used[j] = false;
    }
    used[i] = false;
  }
  return 0;
}
