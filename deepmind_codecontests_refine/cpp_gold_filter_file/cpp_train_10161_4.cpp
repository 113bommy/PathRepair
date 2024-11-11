#include <bits/stdc++.h>
using namespace std;
int N, K;
int a[50];
vector<int> v;
vector<pair<int, int> > p;
int ans[1010];
int main(void) {
  int i, j;
  cin >> N >> K;
  for ((i) = 0; (i) < (int)(K); (i)++) cin >> a[i];
  int sum = N;
  for ((i) = 0; (i) < (int)(K); (i)++) {
    int tmp = min(min(a[i], N / 2), sum);
    sum -= tmp;
    p.push_back(make_pair(tmp, i));
  }
  sort(p.begin(), p.end());
  if (sum != 0) {
    cout << -1 << endl;
    return 0;
  }
  if (N % 2 == 0) {
    for ((i) = 0; (i) < (int)(N / 2); (i)++) v.push_back(2 * i);
    for ((i) = 0; (i) < (int)(N / 2); (i)++) v.push_back(2 * i + 1);
  } else {
    for ((i) = 0; (i) < (int)(N); (i)++) v.push_back(2 * i % N);
  }
  int k = 0;
  for ((i) = 0; (i) < (int)(p.size()); (i)++) {
    int x = p[i].second + 1;
    for ((j) = 0; (j) < (int)(p[i].first); (j)++) {
      ans[v[k]] = x;
      k++;
    }
  }
  for ((i) = 0; (i) < (int)(N); (i)++) {
    printf("%d", ans[i]);
    if (i == N - 1)
      printf("\n");
    else
      printf(" ");
  }
  return 0;
}
