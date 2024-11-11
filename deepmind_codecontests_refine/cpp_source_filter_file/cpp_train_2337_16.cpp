#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e+5 + 5;
const int block = 1000;
long long n, d, x;
int a[maxn], b[maxn];
int one[block];
pair<int, int> buffer[maxn];
int getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (int i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int main() {
  cin >> n >> d >> x;
  initAB();
  if (d <= block) {
    int num = 0;
    for (int i = 0; i < n; i++)
      if (b[i]) one[num++] = i;
    for (int i = 0; i < n; i++) {
      int ci = 0;
      for (int j = 0; j < d; j++) {
        if (one[j] > i) break;
        ci = max(ci, a[i - one[j]] * b[one[j]]);
      }
      printf("%d\n", ci);
    }
    return 0;
  }
  priority_queue<pair<int, int> > q;
  int cur = 0;
  int bcur = 0;
  for (int i = 0; i < n; i++) {
    q.push(make_pair(a[i], i));
    int num = 200;
    bcur = cur;
    int ci = 0;
    while (num && !q.empty()) {
      num--;
      buffer[cur] = q.top();
      q.pop();
      ci = max(ci, buffer[cur].first * b[i - buffer[cur].second]);
      cur++;
      if (ci != 0) break;
    }
    for (int j = 0; j < cur; j++) q.push(buffer[j]);
    cur = 0;
    printf("%d\n", ci);
  }
  return 0;
}
