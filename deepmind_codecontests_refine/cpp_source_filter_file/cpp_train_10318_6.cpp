#include <bits/stdc++.h>
using namespace std;
int cnt[11010];
int A[11010];
int where[11010];
int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  int howMany = 0;
  for (int i = 1; i <= 100; i++) {
    if (cnt[i] == 1) {
      howMany++;
    }
  }
  if (howMany % 2) {
    if (howMany == N) {
      cout << "NO" << endl;
    } else {
      bool is = false;
      int which;
      for (int i = 1; i <= 100; i++) {
        if (cnt[i] >= 3) {
          is = true;
          which = i;
          break;
        }
      }
      if (is) {
        cout << "YES" << endl;
        int val = 0;
        bool okay = false;
        for (int i = 1; i <= 100; i++) {
          if (cnt[i] == 0) continue;
          if (cnt[i] == 1) {
            if (val < (howMany / 2 + 1)) {
              val++;
              where[i] = 1;
            } else {
              where[i] = 2;
            }
          } else {
            if (i == which) {
              where[i] = 2;
            } else {
              where[i] = 1;
            }
          }
        }
        for (int i = 1; i <= N; i++) {
          if (cnt[A[i]] and A[i] != which) {
            if (where[A[i]]) {
              if (where[A[i]] == 1) {
                cout << "A";
              } else {
                cout << "B";
              }
            }
          }
          if (cnt[A[i]]) {
            if (okay) {
              cout << "A";
            } else {
              cout << "B";
              okay = true;
            }
          }
        }
        cout << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  } else {
    cout << "YES" << endl;
    int val = 0;
    for (int i = 1; i <= 100; i++) {
      if (cnt[i] == 1) {
        if (val < howMany / 2) {
          val++;
          where[i] = 1;
        } else {
          where[i] = 2;
        }
      }
    }
    for (int i = 1; i <= N; i++) {
      if (cnt[A[i]]) {
        if (where[A[i]]) {
          if (where[A[i]] == 1) {
            cout << "A";
          } else {
            cout << "B";
          }
        } else {
          cout << "A";
        }
      }
    }
    cout << endl;
  }
  return 0;
}
