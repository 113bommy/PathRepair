#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int n, m, k;
string h[1005], v[1005];
int a[1005][1005];
bool check() {
  int total = n * (m - 1) + m * (n - 1);
  int good = 0;
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m - 1); j++) {
      good += ((v[i][j] == 'E') == (a[i][j] == a[i][j + 1]));
    }
  }
  for (int i = 0; i < (int)(n - 1); i++) {
    for (int j = 0; j < (int)(m); j++) {
      good += ((h[i][j] == 'E') == (a[i][j] == a[i + 1][j]));
    }
  }
  return good * 4 >= total * 3;
}
void readdata() {
  cin >> n >> m >> k;
  for (int i = 0; i < (int)(n); i++) {
    cin >> v[i];
    if (i < n - 1) {
      cin >> h[i];
    }
  }
}
bool solve() {
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++) a[i][j] = 0;
  if (k == 1) {
    return check();
  }
  if (n > m) {
    for (int i = 0; i < (int)(n); i++) {
      a[i][0] = 0;
      for (int j = 1; j <= (int)(m - 1); j++) {
        a[i][j] = a[i][j - 1] ^ (v[i][j - 1] == 'N');
      }
      if (i) {
        int bad = 0;
        for (int j = 0; j < (int)(m); j++) {
          if ((h[i - 1][j] == 'E') != (a[i - 1][j] == a[i][j])) bad++;
        }
        if (bad * 2 > m) {
          for (int j = 0; j < (int)(m); j++) a[i][j] ^= 1;
        }
      }
    }
  } else {
    for (int j = 0; j < (int)(m); j++) {
      a[0][j] = 0;
      for (int i = 1; i <= (int)(n - 1); i++) {
        a[i][j] = a[i - 1][j] ^ (h[i - 1][j] == 'N');
      }
      if (j) {
        int bad = 0;
        for (int i = 0; i < (int)(n); i++) {
          if ((v[i][j - 1] == 'E') != (a[i][j] == a[i][j - 1])) bad++;
        }
        if (bad * 2 > n) {
          for (int i = 0; i < (int)(n); i++) a[i][j] ^= 1;
        }
      }
    }
  }
  return check();
}
void outdata() {
  cout << "YES\n";
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) printf("%d ", a[i][j] + 1);
    printf("\n");
  }
}
void gendata() {
  n = rand() % 1000 + 2;
  m = rand() % 1000 + 2;
  k = rand() % 100 + 2;
  for (int i = 0; i < (int)(n); i++) {
    v[i] = "";
    for (int j = 0; j < (int)(m - 1); j++)
      if (rand() & 1)
        v[i] += 'E';
      else
        v[i] += 'N';
    if (i < n - 1) {
      h[i] = "";
      for (int j = 0; j < (int)(m); j++)
        if (rand() & 1)
          h[i] += 'E';
        else
          h[i] += 'N';
    }
  }
}
void stress() {
  for (int it = 0; it < (int)(1000); it++) {
    gendata();
    cerr << it + 1 << endl;
    if (solve()) {
      assert(check());
    }
  }
  exit(0);
}
int main() {
  readdata();
  if (!solve()) {
    cout << "NO" << endl;
  } else {
    assert(check());
    outdata();
  }
  return 0;
}
