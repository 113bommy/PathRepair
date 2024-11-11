#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
typedef struct R {
  int id, l, r, cnt;
} R;
bool operator<(const R &a, const R &b) {
  if (a.r != b.r) return a.r < b.r;
  return a.id < b.id;
}
R need[100000];
int nneed;
R have[100000];
int nhave;
set<pair<int, int> > state;
int ret[100000];
void run() {
  scanf("%d", &nneed);
  for (int i = (0); i < (nneed); ++i) {
    need[i].id = i;
    scanf("%d%d", &need[i].l, &need[i].r);
    need[i].cnt = 1;
  }
  sort(need, need + nneed);
  scanf("%d", &nhave);
  for (int i = (0); i < (nhave); ++i) {
    have[i].id = i;
    scanf("%d%d%d", &have[i].l, &have[i].r, &have[i].cnt);
  }
  sort(have, have + nhave);
  int atneed = 0, athave = 0;
  state = set<pair<int, int> >();
  while (atneed < nneed || athave < nhave) {
    if (athave >= nhave || atneed < nneed && need[atneed].r <= have[athave].r) {
      state.insert(make_pair(need[atneed].l, need[atneed].id));
      ++atneed;
    } else {
      for (int i = (0); i < (have[athave].cnt); ++i) {
        set<pair<int, int> >::iterator it =
            state.lower_bound(make_pair(have[athave].l, -1));
        if (it == state.end()) break;
        ret[it->second] = have[athave].id;
        state.erase(it);
      }
      ++athave;
    }
  }
  if (((int)(state).size()) != 0) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = (0); i < (nneed); ++i) {
    if (i != 0) printf(" ");
    printf("%d", ret[i] + 1);
  }
  puts("");
}
int main() {
  run();
  return 0;
}
