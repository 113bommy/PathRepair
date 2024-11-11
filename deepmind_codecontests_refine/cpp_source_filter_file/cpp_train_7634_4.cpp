#include <bits/stdc++.h>
using namespace std;
pair<int, int> elem[100000];
long long sum[100001];
int pos[100000];
long long b;
int N, K;
int main(void) {
  cin >> N >> K >> b;
  for (int i = 0; i < N; i++) {
    cin >> elem[i].first;
    elem[i].first = -elem[i].first;
    elem[i].second = i;
  }
  sort(elem, &elem[N]);
  for (int i = 0; i < N; i++) pos[elem[i].second] = i;
  for (int i = 0; i < N; i++) sum[i + 1] = sum[i] - elem[i].first;
  for (int free = 0; free < N; free++) {
    long long somma = sum[K - 1];
    if (pos[free] < K - 1) {
      somma += elem[pos[free]].first;
      somma -= elem[K - 1].first;
    }
    if (somma - elem[pos[free]].first > b) {
      cout << free + 1;
      return 0;
    }
  }
  cout << N;
  return 0;
}
