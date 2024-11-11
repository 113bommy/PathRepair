#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int matrix[20][20];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n * n; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }
  bool rem1 = 0;
  int sk = -1;
  int rem2 = 0;
  vector<int> sk2;
  for (auto i : mp) {
    if (i.second % 4 == 0) continue;
    if (i.second % 4 == 1 && n % 2 && !rem1) {
      rem1 = 1;
      sk = i.first;
    } else if (i.second % 4 == 2 && n % 2 && rem2 < n + 1) {
      rem2++;
      sk2.push_back(i.first);
    } else if (i.second % 4 == 3 && n % 2 && !rem1 && rem2 < n + 1) {
      rem1 = 1;
      sk = i.first;
      rem2++;
      sk2.push_back(i.first);
    } else {
      cout << "NO";
      return 0;
    }
  }
  queue<int> q;
  for (auto i : mp) {
    for (int j = 0; j < i.second / 4; j++) {
      q.push(i.first);
    }
  }
  if (sk == -1 && n % 2) {
    cout << "NO";
    return 0;
  } else if (n % 2) {
    mp[sk]--;
    matrix[n / 2][n / 2] = sk;
    for (int i = 0; i < n / 2; i++) {
      if (sk2.size()) {
        matrix[i][n / 2] = sk2.back();
        matrix[n - i - 1][n / 2] = sk2.back();
        sk2.pop_back();
        matrix[n / 2][i] = sk2.back();
        matrix[n / 2][n - i - 1] = sk2.back();
        sk2.pop_back();
      } else {
        matrix[i][n / 2] = q.front();
        matrix[n - i - 1][n / 2] = q.front();
        matrix[n / 2][i] = q.front();
        matrix[n / 2][n - i - 1] = q.front();
        q.pop();
      }
    }
  }
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      matrix[i][j] = q.front();
      matrix[n - i - 1][n - j - 1] = q.front();
      matrix[i][n - j - 1] = q.front();
      matrix[n - i - 1][j] = q.front();
      q.pop();
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
