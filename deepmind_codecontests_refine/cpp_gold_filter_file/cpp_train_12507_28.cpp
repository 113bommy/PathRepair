#include <bits/stdc++.h>
using namespace std;
int main() {
  int chap;
  cin >> chap;
  vector<pair<int, int>> marks;
  pair<int, int> pii;
  for (int i = 0; i < chap; i++) {
    int a, b;
    cin >> a >> b;
    pii = make_pair(a, b);
    marks.push_back(pii);
  }
  int now;
  cin >> now;
  for (int i = 0; i < chap; i++) {
    if (now >= marks[i].first && now <= marks[i].second) {
      cout << chap - i << endl;
    }
  }
  return 0;
}
