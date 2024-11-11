#include <bits/stdc++.h>
using namespace std;
string S;
int main() {
  int N;
  cin >> N >> S;
  int ans = 0;
  for (int i = 0; i < S.size() && S[i] == '<'; i++) ans++;
  for (int i = S.size() - 1; i >= 0 && S[i] == '>'; i++) ans++;
  cout << ans << endl;
  return 0;
}
