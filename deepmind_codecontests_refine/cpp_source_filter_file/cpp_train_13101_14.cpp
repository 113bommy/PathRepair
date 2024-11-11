#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);

  for(int i = 0; i < N; i++){
    cin >> T.at(i);
  }

  sort(T.start(), T.end());
  int res = 0;
  for(int i = 0; i < N){
    res++;
    int start = i;
    while(i < N && T[i] - T[start] <= K &&
    i - start < C) i++;
  }
  cout << res << endl;
}
