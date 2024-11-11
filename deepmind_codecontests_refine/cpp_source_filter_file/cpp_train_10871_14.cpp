#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int N;
int A[1111];
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  cin >> N;
  for (int(i) = 0; (i) < (N); (i)++) cin >> A[i];
  int mnmx = INF;
  int best_head = -1, bestd = -1;
  sort(A, A + N);
  vector<pair<int, int> > v;
  for (int initv = -20000; initv <= 20000; initv++) {
    v.push_back(make_pair(abs(initv), initv));
  }
  sort(v.begin(), v.end());
  for (int(index) = 0; (index) < (int((v).size())); (index)++) {
    int initv = v[index].second;
    for (int d = 0; A[N - 1] + (N - 1) * d <= 20000; d++) {
      int curmx = 0;
      for (int i = 0; i < N; i++) {
        curmx = max(curmx, abs((initv + i * d) - A[i]));
        if (curmx > mnmx) break;
      }
      if (curmx < mnmx) {
        mnmx = curmx;
        best_head = initv;
        bestd = d;
      }
    }
  }
  assert(mnmx < INF);
  cout << mnmx << '\n' << best_head << " " << bestd << '\n';
}
