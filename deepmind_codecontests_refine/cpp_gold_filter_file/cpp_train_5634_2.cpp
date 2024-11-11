#include <bits/stdc++.h>
using namespace std;
int x, y;
char arr[1009][1009];
char out[1009][1009];
vector<pair<long long int, long long int> > vec;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y;
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++) cin >> arr[i][j], out[i][j] = '.';
  for (int i = 1; i < x; i++) {
    for (int j = 1; j < y; j++) {
      int counter = 0;
      if (arr[i - 1][j - 1] != '#') counter++;
      if (arr[i - 1][j] != '#') counter++;
      if (arr[i - 1][j + 1] != '#') counter++;
      if (arr[i][j - 1] != '#') counter++;
      if (arr[i][j + 1] != '#') counter++;
      if (arr[i + 1][j - 1] != '#') counter++;
      if (arr[i + 1][j] != '#') counter++;
      if (arr[i + 1][j + 1] != '#') counter++;
      if (counter == 0) vec.push_back(make_pair(i, j));
    }
  }
  for (int i = 0; i < vec.size(); i++) {
    int row = vec[i].first, col = vec[i].second;
    out[row - 1][col - 1] = '#';
    out[row - 1][col] = '#';
    out[row - 1][col + 1] = '#';
    out[row][col - 1] = '#';
    out[row][col + 1] = '#';
    out[row][col - 1] = '#';
    out[row + 1][col - 1] = '#';
    out[row + 1][col] = '#';
    out[row + 1][col + 1] = '#';
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (arr[i][j] != out[i][j]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
