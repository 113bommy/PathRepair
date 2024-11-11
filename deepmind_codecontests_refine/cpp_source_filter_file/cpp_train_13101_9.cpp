#include <bits/stdc++.h>
using namespace std;

int main() {
  int cnt=0, N, C, K, s=0;
  bool flg = true;
  cin >> N >> C >> K;
  vector<int> T(N,0);
  for (int i = 0; i<N; i++) cin >> T[i];
  sort(T.begin(),T.end());
  for (int i = 1; i<N; i++) {
    if(T[i]>T[s]+K || i=s+C) {
      cnt++;
      s=i;
    }
  }
  cout << cnt << "\n";
}