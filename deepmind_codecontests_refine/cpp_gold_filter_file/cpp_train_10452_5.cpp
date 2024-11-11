#include <bits/stdc++.h>
using namespace std;
struct nd {
  long long a, b, ind;
};
bool cmp(nd a, nd b) {
  if (a.b < b.b)
    return 1;
  else if (a.b > b.b)
    return 0;
  return a.a > b.a;
}
int n, p, k;
vector<nd> vec;
string st;
int main() {
  cin >> n >> p >> k;
  vec.resize(n);
  for (int i = 0; i < n; i++) cin >> vec[i].a >> vec[i].b, vec[i].ind = i + 1;
  sort((vec).begin(), (vec).end(), cmp);
  priority_queue<pair<long long, long long> > q;
  for (int i = p - k; i < n; i++) q.push(make_pair(vec[i].a, i));
  long long low = 1 << 30;
  for (int i = 0; i < k; i++) {
    cout << vec[q.top().second].ind << ' ';
    low = min(low, q.top().second);
    q.pop();
  }
  low--;
  for (int i = 0; i < p - k; i++) cout << vec[low--].ind << ' ';
  return 0;
}
