#include <bits/stdc++.h>
using namespace std;
fstream fin("B.in");
int N, M, K;
bool m[2 * 10005][12];
int sent[10005], received[15];
int cnt[2 * 10005];
int main() {
  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> m[i][j];
    }
  }
  int x, chat;
  for (int i = 0; i < K; ++i) {
    cin >> x >> chat;
    ++sent[x];
    ++received[chat];
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j)
      if (m[i][j]) cnt[i] += received[j];
  }
  for (int i = 1; i <= N; ++i) {
    cout << cnt[i] - sent[i] << ' ';
  }
  fin.close();
  return 0;
}
