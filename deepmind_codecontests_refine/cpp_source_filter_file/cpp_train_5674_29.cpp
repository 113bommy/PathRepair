#include <bits/stdc++.h>
using namespace std;
int N, M;
int Candidates[100];
int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int MaxVotesNum = 0;
    int idx = -1;
    for (int j = 0; j < N; j++) {
      int Temp;
      cin >> Temp;
      if (MaxVotesNum < Temp) {
        MaxVotesNum = Temp;
        idx = j;
      }
    }
    Candidates[idx]++;
  }
  cout << (max_element(Candidates, Candidates + 100) - Candidates) + 1 << endl;
}
