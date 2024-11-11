#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> card(N);
  for (int i=0; i < N; i++) {
    cin >> card.at(i);
  }
  vector<int> count(N + 1, 0);
  for (int i=0; i < N; i++) {
    count.at(card.at(i))++;
  }
  vector<int> deg(N + 1, 0);
  for (int i=1; i <= N; i++) {
    deg.at(count.at(i))++;
  }
  vector<int> kdsum(N + 1, 0), dsum(N + 1, 0);
  for (int i=1; i <= N; i++) {
    kdsum.at(i) = kdsum.at(i - 1) + i * deg.at(i);
    dsum.at(i) = dsum.at(i - 1) + deg.at(i);
  }
  vector<int> fx(N + 1, 0);
  for (int i=1; i <= N; i++) {
      fx.at(i) = kdsum.at(i) / i + (dsum.at(N) - dsum.at(i));
  }
  sort(fx.begin(), fx.end());
  for (int k=1; k <= N; k++) {
    cout << N + 1 - ( lower_bound(fx.begin(), fx.end(), k) - fx.begin() ) << endl;
  }
}