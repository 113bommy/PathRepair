#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 10;
char a[maxn];
int b[maxn];
int rec[4][11];
int en1[11], en0[11] = {0};
void solve(char p, int k) {
  int bit[11] = {0};
  for (int i = 1; i <= 10; i++) {
    bit[i] = k >> (10 - i);
    k -= bit[i] * (1 << (10 - i));
  }
  if (p == '|') {
    for (int i = 1; i <= 10; i++) {
      en1[i] = en1[i] | bit[i];
    }
    for (int i = 1; i <= 10; i++) {
      en0[i] = en0[i] | bit[i];
    }
  } else if (p == '&') {
    for (int i = 1; i <= 10; i++) {
      en1[i] = en1[i] & bit[i];
    }
    for (int i = 1; i <= 10; i++) {
      en0[i] = en0[i] & bit[i];
    }
  } else {
    for (int i = 1; i <= 10; i++) {
      en1[i] = en1[i] ^ bit[i];
    }
    for (int i = 1; i <= 10; i++) {
      en0[i] = en0[i] ^ bit[i];
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  memset(rec, 0, sizeof(rec));
  for (int i = 1; i <= 10; i++) en1[i] = 1;
  for (int i = 1; i <= 10; i++) rec[2][i] = 1;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    solve(a[i], b[i]);
  }
  for (int i = 1; i <= 10; i++) {
    if (en0[i] && en1[i]) {
      rec[1][i] = 1;
    } else if (en1[i] && !en0[i]) {
      rec[1][i] = 0;
    } else if (!en1[i] && en0[i]) {
      rec[3][i] = 1;
    } else if (!en1[i] && !en0[i]) {
      rec[2][i] = 0;
    }
  }
  int A = 0, B = 0, C = 0;
  for (int i = 1; i <= 10; i++) {
    A = A + rec[1][i] * (1 << (10 - i));
  }
  for (int i = 1; i <= 10; i++) {
    B = B + rec[2][i] * (1 << (10 - i));
  }
  for (int i = 1; i <= 10; i++) {
    C = C + rec[3][i] * (1 << (10 - i));
  }
  cout << "3" << endl;
  cout << "| " << A << endl;
  cout << "& " << B << endl;
  cout << "^ " << C << endl;
}
