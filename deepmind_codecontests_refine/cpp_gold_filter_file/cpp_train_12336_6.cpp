#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long power(unsigned long long a, unsigned long long b,
                unsigned long long ret = 1LL) {
  while (b--) ret = (ret * a);
  return ret;
}
string s, t;
int dp[1000 + 9][1000 + 9];
int minchange(int i, int j) {
  if (i == s.size()) {
    return t.size() - j;
  }
  if (j == t.size()) {
    return s.size() - i;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (s[i] == t[j]) return dp[i][j] = minchange(i + 1, j + 1);
  int del = minchange(i + 1, j) + 1;
  int ins = minchange(i, j + 1) + 1;
  int rep = minchange(i + 1, j + 1) + 1;
  return dp[i][j] = min(del, min(rep, ins));
}
int shifting = 0;
void print(int i, int j) {
  if (i == s.size()) {
    int size = t.size() - j;
    for (size_t c = 0; c < size; c++) {
      cout << "INSERT"
           << " ";
      cout << shifting + i + 1 << " " << t[j + c] << endl;
      shifting++;
    }
    return;
  }
  if (j == t.size()) {
    int size = s.size() - i;
    for (size_t c = 0; c < size; c++) {
      cout << "DELETE " << shifting + i + 1 << endl;
      shifting;
    }
    return;
  }
  if (s[i] == t[j]) {
    print(i + 1, j + 1);
    return;
  }
  int parent = minchange(i, j);
  int del = minchange(i + 1, j) + 1;
  int ins = minchange(i, j + 1) + 1;
  int rep = minchange(i + 1, j + 1) + 1;
  if (parent == del) {
    cout << "DELETE " << shifting + i + 1 << endl;
    shifting--;
    print(i + 1, j);
  } else if (parent == ins) {
    cout << "INSERT"
         << " ";
    cout << shifting + i + 1 << " " << t[j] << endl;
    shifting++;
    print(i, j + 1);
  } else if (parent == rep) {
    cout << "REPLACE"
         << " " << i + shifting + 1 << " " << t[j] << endl;
    print(i + 1, j + 1);
  }
}
int main() {
  for (int i = 0; i < 1000 + 9; i++) {
    for (int i2 = 0; i2 < 1000 + 9; i2++) {
      dp[i][i2] = -1;
    }
  }
  cin >> s >> t;
  cout << minchange(0, 0) << endl;
  print(0, 0);
}
