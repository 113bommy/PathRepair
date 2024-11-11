#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> ma, mm;
int main() {
  int n;
  cin >> n;
  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    ma[a] = i;
  }
  int Max = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    mm[(a - ma[a] + n) % n]++;
  }
  for (auto i : mm) Max = max(Max, i.second);
  cout << Max << endl;
}
