#include <bits/stdc++.h>
using namespace std;
const int N = 504;
int a[N], h[N];
vector<pair<int, int> > vec;
vector<pair<int, int> > ans;
pair<int, int> arr[N];
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    arr[i] = make_pair(a[i], i);
  }
  sort(arr + 1, arr + n + 1);
  priority_queue<pair<int, int> > pq;
  int s = arr[1].second;
  int r = arr[2].second;
  pq.push(make_pair(arr[1].first - 1, s));
  pq.push(make_pair(arr[2].first - 1, r));
  h[s] = 1, h[r] = 1;
  int pr = 1, cnt = 1;
  for (i = 3; i <= n; i++) {
    if (arr[i].first > 1) {
      vec.push_back(make_pair(pr, arr[i].second));
      pq.push(make_pair(arr[i].first - 2, arr[i].second));
      h[arr[i].second]++;
      pr = arr[i].second;
      cnt++;
    }
  }
  vec.push_back(make_pair(pr, r));
  for (i = 1; i <= n; i++) {
    if (!h[i]) {
      pair<int, int> p = pq.top();
      if (p.first <= 0) {
        printf("NO\n");
        return 0;
      } else {
        pq.pop();
        pq.push({p.first - 1, p.second});
        vec.push_back({p.second, i});
        h[i] = 1;
      }
    }
  }
  printf("YES %d\n", cnt);
  printf("%d\n", vec.size());
  for (i = 0; i < vec.size(); i++)
    printf("%d %d\n", vec[i].first, vec[i].second);
  return 0;
}
