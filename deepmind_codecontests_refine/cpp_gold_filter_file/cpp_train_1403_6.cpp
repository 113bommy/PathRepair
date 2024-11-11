#include <bits/stdc++.h>
using namespace std;
struct data {
  int x;
  int idx;
};
bool comp(data a, data b) { return b.x > a.x; }
int main() {
  data ara[105];
  vector<int> v;
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    cin >> ara[i].x;
    ara[i].idx = i + 1;
  }
  int cnt = 0;
  sort(ara, ara + a, comp);
  if (ara[0].x > b)
    cout << "0" << endl;
  else {
    int sum = 0;
    for (int i = 0; i < a; i++) {
      if (sum + ara[i].x <= b) {
        cnt++;
        v.push_back(ara[i].idx);
      }
      sum += ara[i].x;
      if (sum > b) break;
    }
    cout << cnt << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  }
}
