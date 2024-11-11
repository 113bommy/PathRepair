#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> line(n);
  for (int i = 0; i < n; i++) {
    cin >> line[i];
  }
  int Ans = 11111;
  for (int i = 0; i < n; i++) {
    int x = line[i];
    int time = 15 * x;
    for (int j = 0; j < x; j++) {
      int y;
      cin >> y;
      time += 5 * y;
    }
    Ans = min(Ans, time);
  }
  cout << Ans;
}
