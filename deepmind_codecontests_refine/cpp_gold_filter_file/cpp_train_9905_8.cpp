#include <bits/stdc++.h>
using namespace std;
int N;
int arr[5005];
vector<int> cub[4];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    char x;
    cin >> x;
    if (x == '1') arr[i] ^= 1;
  }
  for (int i = 1; i <= N; i++) {
    char x;
    cin >> x;
    if (x == '1') arr[i] ^= 2;
  }
  for (int i = 1; i <= N; i++) cub[arr[i]].push_back(i);
  for (int i = 0; i <= cub[1].size(); i++)
    for (int j = 0; j <= cub[2].size(); j++) {
      if (i > N / 2 or j > N / 2) continue;
      int a = i;
      int b = j;
      int have = cub[3].size();
      if (a < b)
        have -= b - a, a = b;
      else if (b < a)
        have -= a - b, b = a;
      if (have < 0 or have & 1) continue;
      a += have / 2 + cub[2].size() - j;
      b += have / 2 + cub[1].size() - i;
      if (a > N / 2 or b > N / 2) continue;
      a -= cub[2].size() - j;
      for (int x = 0; x < i; x++) cout << cub[1][x] << " ";
      for (int x = 0; x < a - i; x++) cout << cub[3][x] << " ";
      for (int x = 0; x < cub[2].size() - j; x++) cout << cub[2][x] << " ";
      a += cub[2].size() - j;
      for (int x = 0; x < N / 2 - a; x++) cout << cub[0][x] << " ";
      return 0;
    }
  cout << "-1\n";
  return 0;
}
