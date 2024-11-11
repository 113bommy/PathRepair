#include <bits/stdc++.h>
using namespace std;
int b[1003];
int a[1004], size[1003];
int root(long i) {
  while (a[i] != i) i = a[a[i]];
  return i;
}
void join(long i, long j) {
  i = root(i);
  j = root(j);
  if (size[i] > size[j]) {
    a[j] = i;
    size[i] += size[j];
  } else {
    a[i] = j;
    size[j] += size[i];
  }
}
int v[1003];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long n;
  cin >> n;
  long x, y;
  queue<pair<long, long> > q;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
    size[i] = 1;
  }
  for (long i = 1; i < n; i++) {
    cin >> x >> y;
    if (root(x) != root(y)) {
      join(x, y);
    } else
      q.push(make_pair(x, y));
  }
  int w = 0;
  for (int i = 1; i <= n; i++) {
    int h = root(i);
    if (v[h] == 0) {
      v[h] = 1;
      w++;
      b[w] = h;
    }
  }
  cout << q.size() << endl;
  int i = 1;
  while (!q.empty()) {
    long h = q.front().first;
    long p = q.front().second;
    q.pop();
    cout << h << " " << p << " " << b[i] << " " << b[i + 1] << endl;
    i++;
  }
}
