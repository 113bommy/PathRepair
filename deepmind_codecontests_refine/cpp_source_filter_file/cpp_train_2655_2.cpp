#include <bits/stdc++.h>
using namespace std;
bool visit[1000005];
int main() {
  int n;
  cin >> n;
  vector<int> x;
  int MAX = INT_MIN;
  int y;
  for (int i = 0; i < n; i++) {
    cin >> y;
    x.push_back(y);
    MAX = max(y, MAX);
  }
  int c = 0;
  int i = 0;
  int dirC = 0;
  bool increOn = true;
  bool justStart = true;
  while (c < n) {
    if ((x[i] == 0 || x[i] <= c) && !visit[i]) {
      c++;
      visit[i] = true;
    }
    if (i == x.size() - 1) increOn = false;
    if (i == 0) increOn = true;
    if (i == 0 && justStart == true) {
      i++;
      justStart = false;
      continue;
    }
    if ((i == 0 || i == x.size() - 1) && c <= MAX) {
      dirC++;
    }
    if (increOn)
      i++;
    else
      i--;
  }
  cout << dirC;
}
