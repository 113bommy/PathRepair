#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
int N, M;
int a[kN];
struct Op {
  int type, end, id;
  bool operator<(const Op& o) const {
    if (end != o.end)
      return end > o.end;
    else
      return id > o.id;
  }
};
Op ops[kN];
int ans[kN];
multiset<int> s;
int pop_back() {
  multiset<int>::iterator it = s.end();
  it--;
  int val = *it;
  s.erase(it);
  return val;
}
int pop_front() {
  multiset<int>::iterator it = s.begin();
  int val = *it;
  s.erase(it);
  return val;
}
void rem(int v) {
  multiset<int>::iterator it = s.find(v);
  s.erase(it);
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%d", a + i);
  for (int i = 1; i <= M; i++)
    scanf("%d %d", &ops[i].type, &ops[i].end), ops[i].id = i;
  for (int i = 1; i <= N; i++) s.insert(a[i]);
  sort(ops + 1, ops + 1 + M);
  int ops_c = 1;
  int last_id = 0, last_type;
  for (int i = N; i >= 1; i--) {
    while (ops_c <= M && ops[ops_c].end > i) ops_c++;
    if (ops_c <= M && ops[ops_c].id > last_id && ops[ops_c].end == i) {
      last_id = ops[ops_c].id;
      last_type = ops[ops_c].type;
    }
    if (last_id) {
      if (last_type == 1) {
        ans[i] = pop_back();
      } else {
        ans[i] = pop_front();
      }
    } else {
      ans[i] = a[i];
      rem(a[i]);
    }
  }
  for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
  return 0;
}
