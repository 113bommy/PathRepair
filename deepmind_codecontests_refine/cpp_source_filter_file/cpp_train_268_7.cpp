#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int times[45];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> m;
  for (int i = 0; i < k; i++) cin >> times[i];
  int s = 0;
  for (int i = 0; i < k; i++) s += times[i];
  sort(begin(times), begin(times) + k);
  int currBest = 0;
  for (int numSolves = 0; numSolves < n + 1; numSolves++) {
    if (s * numSolves > m) break;
    int score = 0;
    score += numSolves * (k + 1);
    int timeLeft = m - s * numSolves;
    int numUnsolved = n - numSolves;
    int i = 0;
    while (timeLeft > times[i] && i < k) {
      score += min(timeLeft / times[i], numUnsolved);
      timeLeft -= times[i] * min(timeLeft / times[i], numUnsolved);
      i++;
    }
    currBest = max(score, currBest);
  }
  cout << currBest << "\n";
}
