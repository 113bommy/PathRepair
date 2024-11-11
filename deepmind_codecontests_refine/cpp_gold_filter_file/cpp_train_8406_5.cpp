#include <bits/stdc++.h>
using namespace std;
long long arr[200010];
priority_queue<pair<long long, long long> > pq, pq1;
vector<long long> v;
int main() {
  long long total;
  cin >> total;
  for (long long i = 1; i <= total; i++) {
    scanf("%lld", &arr[i]);
    pq1.push(make_pair(-arr[i], i));
  }
  char p;
  for (long long i = 1; i <= 2 * total; i++) {
    scanf(" %c", &p);
    if (p == '0') {
      long long o = pq1.top().second;
      long long val = -pq1.top().first;
      pq1.pop();
      pq.push(make_pair(val, o));
      v.push_back(o);
    } else {
      long long o = pq.top().second;
      pq.pop();
      v.push_back(o);
    }
  }
  for (long long i = 0; i < v.size(); i++) {
    if (i) printf(" ");
    printf("%lld", v[i]);
  }
  printf("\n");
}
