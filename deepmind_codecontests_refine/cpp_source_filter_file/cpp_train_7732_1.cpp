#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> T;
int main() {
  scanf("%d", &n);
  T.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &T[i]);
  sort(T.begin(), T.end());
  int tottime = 0;
  int answer = 0;
  int penalty = 0;
  for (int i = 0; i < T.size(); i++) {
    if (tottime + T[i] <= 350) {
      answer++;
    } else {
      if (tottime + T[i] <= 530) {
        answer++;
        penalty += T[i] + tottime - 350;
      }
    }
    tottime += T[i];
  }
  printf("%d %d\n", answer, penalty);
}
