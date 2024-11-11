#include <cstring>

#include <iostream>
#include <algorithm>
using namespace std;

long long memo[101][10][1001];

// x以下からちょうどk個でsを作る
long long solve(int x, int k, int s) {
  if(k == 0 && s == 0) return 1;
  if(s < 0) return 0;
  if(x < 0) return 0;
  if(k == 0) return 0;
  long long &res = memo[x][k][s];
  if(res != -1) return res;
  return res = solve(x - 1, k, s) + solve(x - 1, k - 1, s - x);
}

int main() {
  memset(memo, -1, sizeof(memo));
  while(true) {
    int n, s; cin >> n >> s;
    if(n == 0 && s == 0) break;
    cout << solve(100, n, s) << endl;
  }
}