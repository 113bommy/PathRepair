#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  map<string,int> ma;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    ma[S]++;
  }
  cin >> M;
  for (int i = 0; i < M; ++i) {
    string S;
    cin >> S;
    ma[S]--;
  }
  int res = 0;
  for (auto it : ma) res = max(res, it.second);
  cout << res << endl;
}