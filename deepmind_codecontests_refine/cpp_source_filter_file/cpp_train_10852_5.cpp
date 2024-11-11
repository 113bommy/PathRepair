#include <bits/stdc++.h>
using namespace std;
int main() {
  priority_queue<pair<int, int> > PQ;
  vector<pair<int, int> > res, tmp;
  map<pair<int, int>, int> done;
  int p, c, cards[200001];
  scanf("%d %d", &p, &c);
  for (int i = 0; i < p; i++) {
    scanf("%d", &cards[i]);
    if (cards[i] > 0) PQ.push(make_pair(cards[i], i + 1));
  }
  bool flag = true;
  while (!PQ.empty()) {
    if (!flag) break;
    int num = PQ.top().first, ind = PQ.top().second;
    PQ.pop();
    for (int i = 0; i < num; i++) {
      if (PQ.empty()) {
        flag = false;
        break;
      }
      int num2 = (PQ.top().first) - 1, ind2 = PQ.top().second;
      PQ.pop();
      if (done.count(make_pair(ind, ind2)) == 0) {
        if (num2 > 0) PQ.push(make_pair(num2, ind2));
        res.push_back(make_pair(ind, ind2));
        done[make_pair(ind, ind2)] = 1;
      } else {
        tmp.push_back(make_pair(num2 + 1, ind2));
        i--;
      }
    }
    for (int i = 0; i < tmp.size(); i++) PQ.push(tmp[i]);
    tmp.clear();
  }
  if (res.size() > 0) {
    cout << "Yes" << endl << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
      cout << res[i].first << " " << res[i].second << endl;
  } else
    cout << "No" << endl;
  return 0;
}
