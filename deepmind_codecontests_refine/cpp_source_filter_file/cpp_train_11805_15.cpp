#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<int> v1, v2;
int main() {
  int i, j;
  int x1, x2;
  cin >> N >> M >> K;
  for (i = 0; i < N; i++) {
    int temp;
    scanf("%d", &temp);
    v1.push_back(temp);
  }
  for (i = 0; i < M; i++) {
    int temp;
    scanf("%d", &temp);
    v2.push_back(temp);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  for (x1 = x2 = 0; x1 < N && x2 < M;) {
    if (v1[x1] > v2[x2]) {
      x2++;
    } else if (v1[x1] <= v2[x2]) {
      x1++;
      x2++;
    }
  }
  if (x1 == N && x2 < M) {
    puts("NO");
  } else {
    puts("YES");
  }
}
