#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  vector<int> p(n), probtime(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> probtime[i];
  }
  int time = 0, sc1 = 0, sc2 = 0;
  for (int i = 0; i < n; i++) {
    time += probtime[i];
    sc1 += max(0, p[i] - c * time);
  }
  time = 0;
  for (int i = n - 1; i >= 0; i--) {
    time += probtime[i];
    sc2 += max(0, p[i] - c * time);
  }
  if (sc1 < sc2)
    cout << "Radewoosh" << endl;
  else if (sc1 > sc2)
    cout << "Limak" << endl;
  else
    cout << "Tie" << endl;
}
