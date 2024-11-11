#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int n;
int p[300005];
int t = 1;
long long total;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  q.push(p[1]);
  for (int i = 2; i <= n; i++) {
    if (p[i] > q.top()) {
      int temp = q.top();
      total += p[i] - temp;
      q.pop();
      q.push(p[i]);
    }
    q.push(p[i]);
  }
  cout << total << endl;
  return 0;
}
