#include <bits/stdc++.h>
using namespace std;
int N, K;
int A[200005];
int B[200005];
pair<int, int> Diff[200005];
int Money = 0;
int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) Diff[i].first = (A[i] - B[i]), Diff[i].second = i;
  sort(Diff, Diff + N);
  for (int i = 0; i < K; i++) Money += A[Diff[i].second];
  for (int i = K; i < N; i++)
    Money += (Diff[i].first < 0 ? A[Diff[i].second] : B[Diff[i].second]);
  cout << Money << endl;
}
