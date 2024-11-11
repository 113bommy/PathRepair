#include <bits/stdc++.h>
using namespace std;
int readint() {
  int i;
  scanf("%d", &i);
  return i;
}
vector<pair<int, int> > K, T;
vector<vector<int> > result;
int main() {
  int n = readint(), k = readint();
  unsigned long long sum = 0;
  for (int i = 0; i < int(n); ++i) {
    int c = readint(), t = readint();
    sum += 2 * c;
    if (t == 1)
      T.push_back(make_pair(2 * c, i));
    else
      K.push_back(make_pair(2 * c, i));
  }
  result.resize(k);
  sort(K.begin(), K.end());
  sort(T.begin(), T.end());
  unsigned long long R = sum;
  if (T.size() >= k) {
    int first = T[0].first;
    if (!K.empty()) first = min(K[0].first, T[0].first);
    R -= first / 2;
    for (int i = 0; i < int(K.size()); ++i) result[0].push_back(K[i].second);
    for (int i = 0; i <= int(T.size()) - k; ++i)
      result[0].push_back(T[i].second);
    for (int j = 0; j < int(k - 1); ++j) {
      int i = T.size() - 1 - j;
      result[j + 1].push_back(T[i].second);
      R -= T[i].first / 2;
    }
  } else {
    for (int i = 0; i < int(T.size()); ++i) {
      result[i].push_back(T[i].second);
      R -= T[i].first / 2;
    }
    for (int j = 0; j < int(K.size()); ++j) {
      int i = T.size() + j;
      if (i >= k) {
        result[T.size()].push_back(K[j].second);
      } else {
        result[i].push_back(K[j].second);
      }
    }
  }
  cout << (R / 2) << endl;
  printf(".");
  printf("%d\n", (R % 2) ? 5 : 0);
  for (int i = 0; i < int(k); ++i) {
    printf("%d", result[i].size());
    for (int j = 0; j < int(result[i].size()); ++j)
      printf(" %d", result[i][j] + 1);
    printf("\n");
  }
  return 0;
}
