#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000][1000];
int twos[1000][1000];
int fives[1000][1000];
long long memoT[1000][1000];
long long memoF[1000][1000];
void factorize(int i, int j) {
  int x = arr[i][j];
  while (x % 2 == 0) {
    ++twos[i][j];
    x /= 2;
  }
  while (x % 5 == 0) {
    ++fives[i][j];
    x /= 5;
  }
}
long long solveTwos(int i, int j) {
  if (i == n || j == n) return 1 << 30;
  if (!arr[i][j]) return 1 << 30;
  if (i == n - 1 && j == n - 1) return twos[i][j];
  long long &res = memoT[i][j];
  if (res != -1) return res;
  res = twos[i][j];
  long long r1 = solveTwos(i + 1, j);
  long long r2 = solveTwos(i, j + 1);
  res += min(r1, r2);
  return res;
}
long long solveFives(int i, int j) {
  if (i == n || j == n) return 1 << 30;
  if (!arr[i][j]) return 1 << 30;
  if (i == n - 1 && j == n - 1) return fives[i][j];
  long long &res = memoF[i][j];
  if (res != -1) return res;
  res = fives[i][j];
  long long r1 = solveFives(i + 1, j);
  long long r2 = solveFives(i, j + 1);
  res += min(r1, r2);
  return res;
}
void printPathForTwos(int i, int j, long long res) {
  if (i == n - 1 && j == n - 1) return;
  res -= twos[i][j];
  if (solveTwos(i + 1, j) == res) {
    cout << 'D';
    printPathForTwos(i + 1, j, res);
  } else {
    cout << 'R';
    printPathForTwos(i, j + 1, res);
  }
}
void printPathForFives(int i, int j, int res) {
  if (i == n - 1 && j == n - 1) return;
  res -= fives[i][j];
  if (solveFives(i + 1, j) == res) {
    cout << 'D';
    printPathForFives(i + 1, j, res);
  } else {
    cout << 'R';
    printPathForFives(i, j + 1, res);
  }
}
int main() {
  memset(memoT, -1, sizeof memoT);
  memset(memoF, -1, sizeof memoF);
  int x = -1, y = -1;
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      if (arr[i][j])
        factorize(i, j);
      else
        x = i, y = j;
    }
  long long r1 = solveTwos(0, 0);
  long long r2 = solveFives(0, 0);
  if (x != -1 && r1 > 1 && r2 > 1) {
    cout << 1 << '\n';
    for (int i = 0; i < x; ++i) cout << 'D';
    for (int i = 0; i < y; ++i) cout << 'R';
    for (int i = x; i < n; ++i) cout << 'D';
    for (int i = y; i < n; ++i) cout << 'R';
  } else if (r1 < r2) {
    cout << r1 << '\n';
    printPathForTwos(0, 0, r1);
  } else {
    cout << r2 << '\n';
    printPathForFives(0, 0, r2);
  }
  return 0;
}
