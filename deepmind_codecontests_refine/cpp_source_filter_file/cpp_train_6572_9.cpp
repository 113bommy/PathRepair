#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const unsigned int M = 1000000007;
vector<pair<int, int>> graph[100005];
bool visit[100005];
bool isprime(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  char a[505][505];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'X') {
        if (a[i - 1][j - 1] == 'X' && a[i - 1][j + 1] == 'X' &&
            a[i + 1][j - 1] == 'X' && a[i + 1][j + 1] == 'X') {
          count++;
        }
      }
    }
  }
  cout << count << "\n";
  return 0;
}
