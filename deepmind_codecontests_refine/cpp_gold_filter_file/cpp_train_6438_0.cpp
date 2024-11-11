#include <cstdio>
#include <set>
#include <algorithm>

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  std::set<int> set;
  for (int i=0; i<M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a != 1 && b != N) continue;

    int c=(a==1? b:a);
    if (set.count(c))
      return !printf("POSSIBLE\n");

    set.insert(c);
  }

  printf("IMPOSSIBLE\n");
  return 0;
}
