#include <bits/stdc++.h>
const long double PI = acos(-1.0);
const long long llINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
using namespace std;
const int maxn = 2e5 + 7, maxm = 1e6 + 7;
int N, M, K;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  while (N--) {
    cin >> M;
    string data;
    bool flag = 0;
    cin >> data;
    for (int i = 0; i < M - 11; ++i)
      if (data[i] == '8') flag = 1;
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}
