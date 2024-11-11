#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, x, y;
  scanf("%d", &t);
  while (t--) {
    vector<pair<int, int> > edges;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d %d", &x, &y);
      edges.push_back({x, y});
    }
    srand(time(0));
    uniform_int_distribution<int> dist(0, 1);
    default_random_engine gen;
    vector<int> inDeg(n + 1), outDeg(n + 1);
    vector<int> dirCur(m), dirBest(m);
    int steps = 10, ans = 0;
    for (int i = 0; i < steps; i++) {
      fill(inDeg.begin(), inDeg.end(), 0);
      fill(outDeg.begin(), outDeg.end(), 0);
      for (int i = 0; i < m; i++) {
        int x = dist(gen);
        int a = edges[i].first;
        int b = edges[i].second;
        dirCur[i] = x;
        if (x)
          outDeg[a]++, inDeg[b]++;
        else
          outDeg[b]++, inDeg[a]++;
      }
      for (int i = 0; i < m; i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        if (dirCur[i] && outDeg[a] > inDeg[a] && inDeg[b] > outDeg[b]) {
          dirCur[i] = 0;
          outDeg[a]--, inDeg[a]++, outDeg[b]++, inDeg[b]--;
        } else if (!dirCur[i] && inDeg[a] > outDeg[a] && outDeg[b] > inDeg[b]) {
          dirCur[i] = 1;
          outDeg[a]++, inDeg[a]--, outDeg[b]--, inDeg[b]++;
        }
      }
      int anst = 0;
      for (int i = 1; i <= n; i++) {
        anst += (inDeg[i] == outDeg[i]);
      }
      if (anst > ans) {
        ans = anst;
        dirBest = dirCur;
      }
    }
    printf("%d\n", ans);
    for (int i = 0; i < m; i++) {
      printf("%d %d\n", dirBest[i] ? edges[i].first : edges[i].second,
             !dirBest[i] ? edges[i].first : edges[i].second);
    }
  }
  return 0;
}
