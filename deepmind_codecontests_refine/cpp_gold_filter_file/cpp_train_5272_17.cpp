#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200100;
const int Mod_e97 = 1e9 + 7;
int N, M;
void solveOne() {
  if (N <= 3) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if (N == 4) {
    cout << "2\n4\n1\n3\n";
    return;
  }
  for (int i = 1; i <= N; i += 2) cout << i << endl;
  for (int i = 2; i <= N; i += 2) cout << i << endl;
  return;
}
void solveFour() {
  cout << "YES\n";
  vector<int> raspored = {2, 4, 1, 3};
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 1) {
      for (int k = 0; k < 4; k++) cout << (i - 1) * M + raspored[k] << " ";
      cout << endl;
    } else {
      for (int k = 3; k >= 0; k--) cout << (i - 1) * M + raspored[k] << " ";
      cout << endl;
    }
  }
}
void solve() {
  cout << "YES\n";
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 1) {
      for (int k = 2; k <= M; k += 2) cout << (i - 1) * M + k << " ";
      for (int k = 1; k <= M; k += 2) cout << (i - 1) * M + k << " ";
      cout << endl;
    } else {
      for (int k = 1; k <= M; k += 2) cout << (i - 1) * M + k << " ";
      for (int k = 2; k <= M; k += 2) cout << (i - 1) * M + k << " ";
      cout << endl;
    }
  }
}
void solveSmall() {
  if (N == 1 && M <= 3) {
    cout << "NO\n";
    return;
  }
  if (N == 2 && M == 2) {
    cout << "NO\n";
    return;
  }
  if (N == 2 && M == 3) {
    cout << "NO\n";
    return;
  }
  if (N == 3 && M == 2) {
    cout << "NO\n";
    return;
  }
  if (N == 3 && M == 3) {
    cout << "YES\n";
    cout << "6 1 8 \n7 5 3 \n2 9 4\n";
    return;
  }
}
void solveTwoThree() {
  if (N <= 3) {
    solveSmall();
    return;
  }
  vector<int> stupci[4];
  if (N == 4) {
    vector<int> raspored = {2, 4, 1, 3};
    for (int k = 1; k <= M; k++) {
      if (k % 2 == 1) {
        for (int i = 0; i < 4; i++) {
          stupci[k].emplace_back((raspored[i] - 1) * M + k);
        }
      } else {
        for (int i = 3; i >= 0; i--) {
          stupci[k].emplace_back((raspored[i] - 1) * M + k);
        }
      }
    }
  } else {
    for (int k = 1; k <= M; k++) {
      if (k % 2 == 1) {
        for (int i = 2; i <= N; i += 2) {
          stupci[k].emplace_back((i - 1) * M + k);
        }
        for (int i = 1; i <= N; i += 2) {
          stupci[k].emplace_back((i - 1) * M + k);
        }
      } else {
        for (int i = 1; i <= N; i += 2) {
          stupci[k].emplace_back((i - 1) * M + k);
        }
        for (int i = 2; i <= N; i += 2) {
          stupci[k].emplace_back((i - 1) * M + k);
        }
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= N; i++) {
    for (int k = 1; k <= M; k++) {
      cout << stupci[k][i - 1] << " ";
    }
    cout << endl;
  }
}
void load() {
  cin >> N >> M;
  if (M == 1 && N == 1) {
    cout << "YES\n1";
    return;
  }
  if (M == 1) {
    solveOne();
  } else if (M == 2) {
    solveTwoThree();
  } else if (M == 3) {
    solveTwoThree();
  } else if (M == 4) {
    solveFour();
  } else
    solve();
}
int main() {
  load();
  return 0;
}
