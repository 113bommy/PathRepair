#include <bits/stdc++.h>
using namespace std;
int n, c, temp, j, ans;
vector<int> word[1000100];
int arr[1000100];
void add(int l, int r) {
  arr[l]++;
  arr[r + 1]--;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    word[i].push_back(temp);
    for (j = 1; j <= word[i][0]; j++) {
      cin >> temp;
      word[i].push_back(temp);
    }
  }
  int x, y;
  for (int i = 1; i < n; i++) {
    int l = min(word[i][0], word[i + 1][0]);
    for (j = 1; j <= l; j++) {
      x = word[i][j];
      y = word[i + 1][j];
      if (x != y) break;
    }
    if (j > l && word[i][0] > word[i + 1][0]) {
      cout << "-1" << endl;
      return 0;
    }
    if (x != y) {
      if (x < y) {
        add(0, c - y);
        add(c + 1 - x, c - 1);
      } else if (x > y)
        add(c + 1 - x, c - y);
    } else
      add(0, c - 1);
  }
  for (int i = 0; i < c; i++) {
    ans += arr[i];
    if (ans == n - 1) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}
