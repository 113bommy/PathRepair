#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
long double length(vector<pair<int, int> > v1) {
  long double ans = 0;
  for (int(i) = 0; (i) < (3); (i)++) {
    long double x = v1[i].first - v1[i + 1].first;
    long double y = v1[i].second - v1[i + 1].second;
    x = x * x;
    y = y * y;
    ans += sqrt(x + y);
  }
  return ans;
}
int comp(vector<pair<int, int> > v1, vector<pair<int, int> > v2) {
  return length(v1) > length(v2);
}
int N, M;
vector<vector<pair<int, int> > > v;
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  int k = 2;
  vector<pair<int, int> > v2;
  cin >> N >> M;
  for (int(n1) = 0; (n1) < (min(N, k) + 1); (n1)++)
    for (int(m1) = 0; (m1) < (min(M, k) + 1); (m1)++)
      for (int(n3) = 0; (n3) < (min(N, k) + 1); (n3)++)
        for (int(m3) = 0; (m3) < (min(M, k) + 1); (m3)++)
          for (int n2 = max(0, N - k); n2 <= N; n2++)
            for (int m2 = max(0, M - k); m2 <= M; m2++)
              for (int n4 = max(0, N - k); n4 <= N; n4++)
                for (int m4 = max(0, M - k); m4 <= M; m4++) {
                  v2.clear();
                  v2.push_back(make_pair(n1, m1));
                  v2.push_back(make_pair(n2, m2));
                  v2.push_back(make_pair(n3, m3));
                  v2.push_back(make_pair(n4, m4));
                  int flag = 0;
                  for (int(i) = 0; (i) < (4); (i)++)
                    for (int(j) = 0; (j) < (4); (j)++)
                      if (i != j)
                        if (v2[i].first == v2[j].first &&
                            v2[i].second == v2[j].second)
                          flag = 1;
                  if (!flag) {
                    v.push_back(v2);
                  }
                }
  if (!N && !M) {
    v2.clear();
    v2.push_back(make_pair(0, 0));
    v2.push_back(make_pair(N, M));
    v2.push_back(make_pair(N, 0));
    v2.push_back(make_pair(0, M));
    sort(v2.begin(), v2.end());
    do {
      v.push_back(v2);
    } while (next_permutation(v2.begin(), v2.end()));
  }
  sort(v.begin(), v.end(), comp);
  for (int(i) = 0; (i) < (4); (i)++)
    cout << v[0][i].first << " " << v[0][i].second << '\n';
}
