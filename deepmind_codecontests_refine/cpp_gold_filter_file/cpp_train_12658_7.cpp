#include <bits/stdc++.h>
using namespace std;
int N, K, arr[400010], lastUse[400010], nextUse[400010], ret = 0;
set<int> activeBooks;
set<pair<int, int>> shelfLife;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(18);
  cin >> N >> K;
  fill(lastUse, lastUse + 400010, -1);
  fill(nextUse, nextUse + 400010, 400010);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (lastUse[arr[i]] != -1) nextUse[lastUse[arr[i]]] = i;
    lastUse[arr[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    if (activeBooks.find(arr[i]) == activeBooks.end()) {
      if (activeBooks.size() == K) {
        pair<int, int> now = *shelfLife.rbegin();
        activeBooks.erase(now.second);
        shelfLife.erase(now);
      }
      ret++;
    }
    activeBooks.insert(arr[i]);
    shelfLife.erase(make_pair(i, arr[i]));
    shelfLife.insert(make_pair(nextUse[i], arr[i]));
  }
  cout << ret << '\n';
  return 0;
}
