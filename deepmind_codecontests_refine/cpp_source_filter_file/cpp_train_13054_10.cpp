#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-6;
static int sample;
set<int> S;
int k, m;
void DFS(int result, int remain) {
  if (((int)(S).size()) >= m) return;
  if (remain == 0) {
    int gap = abs(k - abs(k - result));
    if (gap < 10000) {
      S.insert(sample * 10000 + gap);
      S.insert(gap * 10000 + sample);
    }
    return;
  }
  DFS(result + remain % 10, remain / 10);
  DFS(result - remain % 10, remain / 10);
  DFS(result * (remain % 10), remain / 10);
}
int main() {
  scanf("%d %d", &k, &m);
  for (int i = 0; i < 10000 && ((int)(S).size()) < m; i++) {
    sample = i;
    DFS(i % 10, i / 10);
  }
  int output = 0;
  for (__typeof((S).begin()) itr = (S).begin(); itr != (S).end(); itr++) {
    if (output++ == m) break;
    printf("%08d\n", *itr);
  }
  return 0;
}
