#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = n + 1; i <= 9012; i++) {
    vector<int> used(10, 0);
    used[i / 1000]++;
    used[(i / 100) % 10]++;
    used[(i / 10) % 10]++;
    used[i % 10]++;
    bool correct = true;
    for (int j = 0; j < 10; j++) {
      if (used[j] > 1) {
        correct = false;
        break;
      }
    }
    if (correct) {
      cout << i;
      break;
    }
  }
}
