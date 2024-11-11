#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 100010;
set<long long int> s;
set<long long int>::iterator itlow, itup;
long long int data[4 * MAXN], ind[4 * MAXN], a[MAXN];
const long long int INF = 10000000000000;
void build(int s = 0, int e = 5e5 + 1, int id = 1) {
  if (e - s < 2) {
    data[id] = a[s];
    ind[id] = s;
    return;
  }
  int mid = (s + e) / 2;
  build(s, mid, 2 * id + 0);
  build(mid, e, 2 * id + 1);
  if (data[2 * id + 0] == 0) data[2 * id + 0] = INF;
  if (data[2 * id + 1] == 0) data[2 * id + 1] = INF;
  data[id] = min(data[2 * id + 0], data[2 * id + 1]);
  if (data[2 * id + 0] < data[2 * id + 1]) {
    ind[id] = ind[2 * id + 0];
  } else {
    ind[id] = ind[2 * id + 1];
  }
}
void update(int p, int s = 0, int e = 5e5 + 1, int id = 1) {
  if (e - s < 2) {
    data[id] = INF;
    ind[id] = s;
    return;
  }
  int mid = (s + e) / 2;
  if (p < mid) {
    update(p, s, mid, 2 * id + 0);
  } else {
    update(p, mid, e, 2 * id + 1);
  }
  if (data[2 * id + 0] == 0) data[2 * id + 0] = INF;
  if (data[2 * id + 1] == 0) data[2 * id + 1] = INF;
  data[id] = min(data[2 * id + 0], data[2 * id + 1]);
  if (data[2 * id + 0] < data[2 * id + 1]) {
    ind[id] = ind[2 * id + 0];
  } else {
    ind[id] = ind[2 * id + 1];
  }
}
int main() {
  for (int i = 0; i < 4 * MAXN; i++) {
    data[i] = INF;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }
  build();
  long long int answer = 0;
  long long int sub = 0;
  long long int num = n;
  for (int i = 0; i < n - 2; i++) {
    long long int mini = data[1] - sub;
    long long int indexi = ind[1];
    answer += (num - 2) * mini;
    sub += mini;
    num--;
    itlow = s.begin();
    itup = s.end();
    itup--;
    if (indexi == *(itlow) or indexi == *(itup)) {
      update(indexi);
      s.erase(indexi);
      continue;
    }
    int lefti, righti;
    itlow = s.lower_bound(indexi);
    itup = s.upper_bound(indexi);
    itlow--;
    answer += min(a[*(itlow)], a[*(itup)]);
    answer -= sub;
    s.erase(indexi);
    update(indexi);
  }
  cout << answer << endl;
}
