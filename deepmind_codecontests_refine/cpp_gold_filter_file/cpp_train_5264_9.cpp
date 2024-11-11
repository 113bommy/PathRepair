#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b) { return a > b; }
int main() {
  long long n, a[50100], x, y;
  priority_queue<long long, vector<long long>, less<long long> > pq;
  set<long long> st;
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    pq.push(a[i]);
    st.insert(a[i]);
  }
  for (int i = 0; i < 1000000; i++) {
    x = pq.top();
    y = x;
    for (int j = 0; j < 40; j++) {
      if (y == 1) break;
      y /= 2;
      if (st.find(y) == st.end()) {
        pq.pop();
        pq.push(y);
        st.erase(x);
        st.insert(y);
        break;
      }
    }
  }
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  return 0;
}
