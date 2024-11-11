#include <bits/stdc++.h>
using namespace std;
long long a, b, n, m, x, sum, ans, res, maxx, cnt, k, l, c;
string s1, s2;
long long used[1000];
int arr[1001][1001];
map<string, int> mp;
vector<long long> V;
set<string> st;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    arr[a][b] = 1;
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      if (arr[i][j] == 1) {
        cnt++;
        break;
      }
    }
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      if (arr[j][i] == 1) {
        ans++;
        break;
      }
    }
  }
  cout << min(ans, cnt) << endl;
}
