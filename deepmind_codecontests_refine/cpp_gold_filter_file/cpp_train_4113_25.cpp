#include <bits/stdc++.h>
using namespace std;
struct trio {
  int a, b, c;
  trio() {}
  trio(int x, int y, int z) { a = x, b = y, c = z; }
};
bool cmp(trio f, trio s) { return f.a > s.a; }
bool isUsed[801];
int ans[801];
int main() {
  int N;
  vector<trio> vec;
  scanf("%d", &N);
  for (int i = 2; i <= N * 2; i++) {
    for (int h = 1; h < i; h++) {
      int curr;
      scanf("%d", &curr);
      vec.push_back(trio(curr, i, h));
    }
  }
  sort(vec.begin(), vec.end(), cmp);
  for (int i = 0; i < vec.size(); i++) {
    if (isUsed[vec[i].b] or isUsed[vec[i].c]) continue;
    ans[vec[i].b] = vec[i].c, ans[vec[i].c] = vec[i].b;
    isUsed[vec[i].b] = isUsed[vec[i].c] = true;
  }
  for (int i = 1; i <= N * 2; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
