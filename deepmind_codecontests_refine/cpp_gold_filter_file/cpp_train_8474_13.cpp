#include <bits/stdc++.h>
using namespace std;
long long int a, n, ans, A[4444], B[4444];
string S;
map<long long, long long> M;
int main() {
  cin >> a >> S;
  for (int i = 0; i < S.size(); i++) A[i + 1] = S[i] - '0', n = i + 1;
  for (int i = 1; i <= n; i++) {
    B[0] = 0;
    for (int j = 0; i + j <= n; j++) {
      B[j + 1] = B[j] + A[i + j];
      M[B[j + 1]] += 1;
    }
  }
  map<long long, long long>::iterator i;
  for (i = M.begin(); i != M.end(); i++) {
    if ((*i).first == 0 || a % (*i).first == 0) {
      ans += (*i).first ? (*i).second * M[a / (*i).first]
             : a == 0   ? M[0] * (n * (n + 1)) / 2
                        : 0;
    }
  }
  cout << ans << endl;
  return 0;
}
