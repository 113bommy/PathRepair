#include <bits/stdc++.h>
using namespace std;
int N;
char s[105][105];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", s[i]);
  }
  vector<pair<int, int> > v1, v2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (s[i][j] == '.') {
        v1.push_back(make_pair(i, j));
        break;
      }
    }
    for (int j = 0; j < N; j++) {
      if (s[j][i] == '.') {
        v2.push_back(make_pair(j, i));
        break;
      }
    }
  }
  if (v1.size() < N && v2.size() < N) {
    printf("%d\n", -1);
    return 0;
  }
  if (v1.size() == N) {
    for (int i = 0; i < N; i++) {
      printf("%d %d\n", v1[i].first + 1, v1[i].second + 1);
    }
  } else {
    for (int i = 0; i < N; i++) {
      printf("%d %d\n", v2[i].first + 1, v2[i].second + 1);
    }
  }
  return 0;
}
