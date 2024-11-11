#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, M, T, i;
  cin >> n >> M >> T;
  int h, m, s;
  vector<int> E;
  for (i = 0; i < n; ++i) {
    scanf("%d:%d:%d", &h, &m, &s);
    E.push_back(h * 3600 + m * 60 + s);
  }
  vector<int> Q(E.size() + 5);
  int begin = 0, end = 0;
  vector<int> ID(E.size());
  int id = 0;
  bool solution = false;
  for (i = 0; i < E.size(); ++i) {
    while (begin != end && E[i] - Q[begin] >= T) ++begin;
    if (end - begin < M) {
      ID[i] = ++id;
      Q[end++] = E[i];
    } else {
      ID[i] = id;
      Q[end] = E[i];
    }
    solution |= (end - begin == M);
  }
  if (!solution) {
    cout << "No solution\n";
    return 0;
  }
  cout << id << "\n";
  for (i = 0; i < ID.size(); ++i) cout << ID[i] << "\n";
  return 0;
}
