#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  const int N = 200;
  cin >> n;
  vector<vector<int>> a(N, vector<int>(N));
  set<int> numbers;
  vector<int> answers[n];
  if (n == 2) {
    int k, b;
    cin >> k;
    cout << k - 1 << ' ';
    for (int j = 0; j < k - 1; j++) {
      cin >> b;
      cout << b << ' ';
    }
    cin >> b;
    cout << endl << 1 << ' ' << b;
    return 0;
  }
  for (int i = 0; 2 * i < n * (n - 1); i++) {
    int k;
    cin >> k;
    int b[k];
    for (int j = 0; j < k; j++) {
      cin >> b[j];
      numbers.insert(b[j]);
    }
    for (int j = 0; j < k; j++) {
      for (int l = j + 1; l < k; l++) {
        a[b[j] - 1][b[l] - 1]++;
        a[b[l] - 1][b[j] - 1]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    answers[i].push_back(*numbers.begin());
    for (int j = 0; j < N; j++) {
      if (a[*numbers.begin() - 1][j] == n - 1) {
        answers[i].push_back(j + 1);
        numbers.erase(j + 1);
      }
    }
    numbers.erase(numbers.begin());
  }
  for (int i = 0; i < n; i++) {
    cout << answers[i].size() << ' ';
    for (int j : answers[i]) {
      cout << j << ' ';
    }
    cout << endl;
  }
}
