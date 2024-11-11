#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int N, startingPoint;
pair<int, int> A[MAX];
int V[2][MAX];
void citire() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i].first, A[i].second = i;
  sort(A + 1, A + N + 1);
}
void solve() {
  int partitionSize = N / 3 + (N % 3 == 2);
  for (int i = 1, partition = 0; i <= N; i++) {
    V[partition][A[i].second] = A[i].first;
    if (i == partitionSize) partition++;
    if (i == 2 * partitionSize + (N % 3 == 1)) {
      startingPoint = i + 1;
      break;
    }
  }
  for (int i = startingPoint, value = partitionSize - 1; i <= N; i++, value--) {
    V[1][A[i].second] = value;
    V[0][A[i].second] = A[i].first - value;
  }
}
void afisare() {
  cout << "YES\n";
  for (int partition = 0; partition < 2; partition++) {
    for (int i = 1; i <= N; i++) cout << V[partition][i] << " ";
    cout << "\n";
  }
}
int main() {
  citire();
  solve();
  afisare();
}
