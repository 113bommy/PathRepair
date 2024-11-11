#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
void fastIO() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fastIO();
  int n, k;
  long long x, nm;
  cin >> n >> k >> x;
  char sign = '+';
  int signP = 0, signM = 0, signZ = 0;
  vector<pair<long long, pair<int, char> > > v;
  for (int i = 0; i < n; i++) {
    cin >> nm;
    if (nm > 0) sign = '+', signP++;
    if (nm < 0) sign = '-', signM++;
    if (nm == '0') sign = '~', signZ++;
    v.push_back(make_pair(abs(nm), make_pair(i, sign)));
  }
  if (signM == 0 && signZ > 0) {
    for (int i = 0; i < n; i++) {
      if (v[i].first == 0) {
        v[i].first = x;
        v[i].second.second = '-';
        k--;
        break;
      }
    }
  } else if (signM % 2 == 0) {
    int mnIndx = v[0].second.first;
    for (int i = 0; i < n; i++) {
      if (v[mnIndx].first > v[i].first) {
        mnIndx = i;
      }
    }
    if (v[mnIndx].second.second == '+') {
      long long val = v[mnIndx].first;
      while (k > 0 && val >= 0) {
        val -= x;
        k--;
      }
      v[mnIndx].first = abs(val);
      if (val < 0) {
        v[mnIndx].second.second = '-';
      } else if (val == 0) {
        v[mnIndx].second.second = '~';
      }
    } else {
      long long val = v[mnIndx].first * -1ll;
      while (k > 0 && val <= 0) {
        val += x;
        k--;
      }
      v[mnIndx].first = abs(val);
      if (val > 0) {
        v[mnIndx].second.second = '+';
      } else if (val == 0) {
        v[mnIndx].second.second = '~';
      }
    }
  }
  priority_queue<pair<long long, pair<int, char> >,
                 vector<pair<long long, pair<int, char> > >,
                 greater<pair<long long, pair<int, char> > > >
      Q;
  for (int i = 0; i < n; i++) {
    Q.push(make_pair(v[i].first,
                     make_pair(v[i].second.first, v[i].second.second)));
  }
  while (k) {
    pair<long long, pair<int, char> > cur = Q.top();
    Q.pop();
    cur.first += x;
    Q.push(cur);
    k--;
  }
  vector<long long> res(n);
  long long val = 0;
  while (!Q.empty()) {
    pair<long long, pair<int, char> > cur = Q.top();
    Q.pop();
    val = cur.first;
    if (cur.second.second == '-') val *= -1;
    res[cur.second.first] = val;
  }
  for (int i = 0; i < n; i++) cout << res[i] << " ";
  return 0;
}
