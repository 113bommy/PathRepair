#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  pair<int, int> home, uni;
  cin >> home.first >> home.second >> uni.first >> uni.second;
  int count;
  cin >> count;
  int solution = 0;
  int a, b, c;
  for (int i = 0; i < count; i++) {
    cin >> a >> b >> c;
    bool h_p = a * home.first + b * home.second + c > 0;
    bool u_p = a * uni.first + b * uni.second + c > 0;
    if ((h_p && !u_p) || (!h_p && u_p)) {
      solution++;
    }
  }
  cout << solution << endl;
  return 0;
}
