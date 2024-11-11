#include <bits/stdc++.h>
using namespace std;
inline bool check(long long b[4][4], long long sum) {
  for (int i = 0; i < 4; i++) {
    long long tmp = 0;
    for (int j = 0; j < 4; j++) {
      tmp += b[i][j];
    }
    if (tmp != sum) return false;
  }
  for (int i = 0; i < 4; i++) {
    long long tmp = 0;
    for (int j = 0; j < 4; j++) {
      tmp += b[j][i];
    }
    if (tmp != sum) return false;
  }
  long long tmp = 0;
  for (int i = 0; i < 4; i++) {
    tmp += b[i][i];
  }
  tmp = 0;
  for (int i = 0; i < 4; i++) {
    tmp += b[3 - i][i];
  }
  return tmp == sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(32);
  int n;
  cin >> n;
  int m = n * n;
  vector<long long> a(m);
  long long sum = 0;
  for (long long &x : a) {
    cin >> x;
    sum += x;
  }
  assert(sum % n == 0);
  sum /= n;
  if (n <= 3) {
    sort(a.begin(), a.end());
    while (true) {
      long long b[n][n];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          b[i][j] = a[n * i + j];
        }
      }
      bool flg = true;
      for (int i = 0; i < n; i++) {
        long long tmp = 0;
        for (int j = 0; j < n; j++) {
          tmp += b[i][j];
        }
        if (tmp != sum) flg = false;
        tmp = 0;
        for (int j = 0; j < n; j++) {
          tmp += b[j][i];
        }
        if (tmp != sum) flg = false;
      }
      long long tmp = 0;
      for (int i = 0; i < n; i++) {
        tmp += b[i][i];
      }
      if (tmp != sum) flg = false;
      tmp = 0;
      for (int i = 0; i < n; i++) {
        tmp += b[n - 1 - i][i];
      }
      if (tmp != sum) flg = false;
      if (flg) {
        cout << sum << '\n';
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
          }
          cout << '\n';
        }
        exit(0);
      }
      if (!next_permutation(a.begin(), a.end())) break;
    }
    assert(false);
  }
  vector<int> pos;
  for (int i = 0; i < 16; i++) {
    for (int j = i + 1; j < 16; j++) {
      for (int k = j + 1; k < 16; k++) {
        for (int l = j + 1; l < 16; l++) {
          if (a[i] + a[j] + a[k] + a[l] == sum) {
            int mask = (1 << i) | (1 << j) | (1 << k) | (1 << l);
            pos.push_back(mask);
          }
        }
      }
    }
  }
  for (int i = 0; i < pos.size(); i++) {
    for (int j = i + 1; j < pos.size(); j++) {
      if (pos[i] & pos[j]) continue;
      for (int k = j + 1; k < pos.size(); k++) {
        if (pos[k] & (pos[i] | pos[j])) continue;
        for (int l = k + 1; l < pos.size(); l++) {
          if (pos[l] & (pos[i] | pos[j] | pos[k])) continue;
          long long b[4][4];
          vector<int> r1, r2, r3, r4;
          for (int ind = 0; ind < 16; ind++) {
            if (pos[i] & (1 << ind)) r1.push_back(a[ind]);
            if (pos[j] & (1 << ind)) r2.push_back(a[ind]);
            if (pos[k] & (1 << ind)) r3.push_back(a[ind]);
            if (pos[l] & (1 << ind)) r4.push_back(a[ind]);
          }
          sort(r1.begin(), r1.end());
          for (int ind = 0; ind < 4; ind++) {
            b[0][ind] = r1[ind];
          }
          sort(r2.begin(), r2.end());
          while (true) {
            for (int ind = 0; ind < 4; ind++) {
              b[1][ind] = r2[ind];
            }
            sort(r3.begin(), r3.end());
            while (true) {
              for (int ind = 0; ind < 4; ind++) {
                b[2][ind] = r3[ind];
              }
              sort(r4.begin(), r4.end());
              while (true) {
                for (int ind = 0; ind < 4; ind++) {
                  b[3][ind] = r4[ind];
                }
                if (check(b, sum)) {
                  for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                      cout << b[i][j] << " ";
                    }
                    cout << '\n';
                  }
                  exit(0);
                }
                if (!next_permutation(r4.begin(), r4.end())) break;
              }
              if (!next_permutation(r3.begin(), r3.end())) break;
            }
            if (!next_permutation(r2.begin(), r2.end())) break;
          }
        }
      }
    }
  }
  return 0;
}
