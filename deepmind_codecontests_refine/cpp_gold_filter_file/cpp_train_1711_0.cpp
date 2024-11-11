#include <bits/stdc++.h>
using namespace std;
int N;
int Array[500005];
bool Use[1000005];
const int S = 1000000;
vector<int> Sol;
void Read() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &Array[i]), Use[Array[i]] = 1;
}
void Solve() {
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (Use[S - Array[i] + 1] == 0) {
      Use[S - Array[i] + 1] = 1;
      Sol.push_back(S - Array[i] + 1);
    } else
      ++cnt;
  }
  int rem = 0;
  if (cnt % 2 == 1) rem = 1;
  cnt /= 2;
  while (cnt > 0) {
    for (int i = 1; i <= S && cnt > 0; i++) {
      if (Use[i] == 1) continue;
      if (Use[S - i + 1] == 1) continue;
      Sol.push_back(i);
      Sol.push_back(S - i + 1);
      --cnt;
    }
  }
}
int main() {
  Read();
  Solve();
  printf("%d\n", Sol.size());
  for (int i = 0; i < Sol.size(); i++) printf("%d ", Sol[i]);
  printf("\n");
  return 0;
}
