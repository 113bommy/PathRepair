#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
long long N, M, K;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> K;
  string cad;
  for (long long i = 1; i <= N - 1; i++) {
    for (long long j = 1; j <= M - 1; j++) {
      cad += "R";
    }
    for (long long j = 1; j <= M - 1; j++) {
      cad += "L";
    }
    cad += "D";
  }
  for (long long j = 1; j <= M - 1; j++) {
    cad += "R";
  }
  for (long long j = 1; j <= M - 1; j++) {
    for (long long i = 1; i <= N - 1; i++) {
      cad += "U";
    }
    for (long long i = 1; i <= N - 1; i++) {
      cad += "D";
    }
    cad += "L";
  }
  for (long long j = 1; j <= M - 1; j++) {
    cad += "U";
  }
  if (cad.size() < K) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  vector<long long> res;
  vector<char> cc;
  char temp = 'X';
  long long cont = 0;
  for (long long i = 0; i < K; i++) {
    if (cad[i] != temp) {
      res.push_back(cont);
      cc.push_back(temp);
      temp = cad[i];
      cont = 1;
    } else {
      cont++;
    }
  }
  res.push_back(cont);
  cc.push_back(temp);
  cout << res.size() - 1 << '\n';
  for (long long i = 1; i < res.size(); i++) {
    cout << res[i] << " " << cc[i] << '\n';
  }
  return 0;
}
