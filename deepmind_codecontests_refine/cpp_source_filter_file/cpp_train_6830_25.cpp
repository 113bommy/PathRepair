#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const double EPS = 1e-5;
int n, start, x;
vector<int> num, nxt;
unsigned int Random() {
  unsigned int r = rand();
  r *= 12387;
  r += rand();
  return r;
}
void ask(int idx) {
  cout << "? " << idx + 1 << endl;
  cin >> num[idx] >> nxt[idx];
  nxt[idx]--;
}
void askRandom(int asks) {
  int found = 0;
  for (int i = 0; i < asks && found < n; i++) {
    int randIdx;
    do {
      randIdx = Random() % n;
    } while (num[randIdx] != -1);
    found++;
    ask(randIdx);
  }
}
int getPrev() {
  vector<pair<int, int> > tmp;
  for (int i = 0; i < n; i++)
    if (num[i] != -1) tmp.push_back(pair<int, int>(num[i], i));
  sort(tmp.begin(), tmp.end());
  auto it = lower_bound(tmp.begin(), tmp.end(), pair<int, int>(x, 0));
  if (it == tmp.end()) return tmp.back().second;
  if (it->first == x) return it->second;
  if (it == tmp.begin()) {
    ask(start);
    return start;
  }
  return prev(it)->second;
}
int find() {
  int cur = getPrev();
  while (nxt[cur] >= 0) {
    if (num[cur] >= x) return num[cur];
    cur = nxt[cur];
    if (num[cur] == -1) ask(cur);
  }
  return num[cur] >= x ? num[cur] : -1;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  srand(time(NULL));
  cin >> n >> start >> x;
  start--;
  num.assign(n, -1);
  nxt = num;
  askRandom(200);
  cout << "! " << find() << endl;
  cin.ignore(), cin.get();
}
