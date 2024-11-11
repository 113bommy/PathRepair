#include <bits/stdc++.h>
using namespace std;
const int M = 1000000000;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
}
int main() {
  int x0, y0, x1, y1, n, r, a, b, i, j, k;
  map<int, vector<pair<int, int> > > m;
  map<int, vector<pair<int, int> > >::iterator it;
  vector<pair<int, int> > v, *pv;
  pair<int, int> tp;
  scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d%d", &r, &a, &b);
    m[r].push_back(make_pair(a, b));
  }
  for (it = m.begin(); it != m.end(); ++it) {
    v = it->second;
    sort(v.begin(), v.end(), cmp);
    pv = &(it->second);
    pv->clear();
    tp = v[0];
    for (i = 1; i < v.size(); ++i) {
      if (tp.second < v[i].first) {
        pv->push_back(tp);
        tp = v[i];
      } else {
        tp.second = max(tp.second, v[i].second);
      }
    }
    pv->push_back(tp);
  }
  set<pair<int, int> > visited;
  queue<pair<int, int> > q;
  q.push(make_pair(x0, y0));
  vector<pair<int, int> > tv;
  int qsize, qi, step = 0, low, high, mid;
  bool found = false;
  while (!q.empty()) {
    qsize = q.size();
    ++step;
    for (qi = 0; qi < qsize; ++qi) {
      tp = q.front();
      q.pop();
      tv.clear();
      tv.push_back(make_pair(tp.first + 1, tp.second));
      tv.push_back(make_pair(tp.first - 1, tp.second));
      tv.push_back(make_pair(tp.first, tp.second + 1));
      tv.push_back(make_pair(tp.first, tp.second - 1));
      tv.push_back(make_pair(tp.first - 1, tp.second - 1));
      tv.push_back(make_pair(tp.first + 1, tp.second + 1));
      tv.push_back(make_pair(tp.first - 1, tp.second + 1));
      tv.push_back(make_pair(tp.first + 1, tp.second - 1));
      for (i = 0; i < tv.size(); ++i) {
        tp = tv[i];
        if (tp.first == x1 && tp.second == y1) {
          found = true;
          break;
        }
        if (tp.first < 1 || tp.first > M || tp.second < 1 || tp.second > M ||
            visited.find(tp) != visited.end() || m.find(tp.first) == m.end()) {
          continue;
        }
        visited.insert(tp);
        pv = &m[tp.first];
        low = 0;
        high = pv->size() - 1;
        while (low <= high) {
          mid = (low + high) / 2;
          if ((*pv)[mid].first <= tp.second && (*pv)[mid].second >= tp.second) {
            q.push(tp);
            break;
          } else if ((*pv)[mid].first > tp.second) {
            high = mid - 1;
          } else {
            low = mid + 1;
          }
        }
      }
      if (found) {
        break;
      }
    }
    if (found) {
      break;
    }
  }
  printf("%d\n", found ? step : -1);
  return 0;
}
