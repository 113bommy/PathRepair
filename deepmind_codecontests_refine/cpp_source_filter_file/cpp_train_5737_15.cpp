#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> lq, rq;
int tryy(int li, int ri) {
  int temp_li = -1, l, r, temp_ri = -1;
  if (lq.top() == li) {
    temp_li = lq.top();
    lq.pop();
    l = lq.top();
    lq.push(temp_li);
  } else {
    l = lq.top();
  }
  if (rq.top() == (-1 * ri)) {
    temp_ri = rq.top();
    rq.pop();
    r = -1 * rq.top();
    rq.push(-1 * temp_ri);
  } else {
    r = -1 * rq.top();
  }
  if ((r - l) >= 0) return (r - l);
  return 0;
}
int main() {
  long long n;
  cin >> n;
  long long l[n], r[n], maxx = -1;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    lq.push(l[i]);
    rq.push(-1 * r[i]);
  }
  for (int i = 0; i < n; i++) {
    int m = tryy(l[i], r[i]);
    if (maxx < m) {
      maxx = m;
    }
  }
  cout << maxx;
}
