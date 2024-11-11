#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      p;
  map<long long, long long> ma;
  for (int i = 0; i < n; i++) {
    long long t;
    cin >> t;
    ma[t]++;
    p.push(make_pair(t, i));
  }
  int l = 0;
  vector<int> v(150005, 0);
  while (!p.empty()) {
    if (ma[p.top().first] > 1) {
      ma[p.top().first] -= 2;
      p.pop();
      long long m = p.top().first * 2;
      long long i = p.top().second;
      p.pop();
      ma[m]++;
      p.push(make_pair(m, i));
    } else {
      long long m = p.top().first;
      long long i = p.top().second;
      p.pop();
      ma[m]--;
      v[i] = m;
      l++;
    }
  }
  cout << l << endl;
  for (int i = 0; i < 150005; i++) {
    if (v[i]) cout << v[i] << " ";
  }
}
