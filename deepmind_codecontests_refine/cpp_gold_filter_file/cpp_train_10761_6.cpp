#include <bits/stdc++.h>
using namespace std;
int best[111111];
pair<int, pair<int, int> > _S[111111];
pair<int, int> S[111111];
struct Segment {
  pair<int, int> bounds;
  pair<int, int> cons;
  int id;
  Segment(int i)
      : id(i), bounds(S[i].first, S[i].second), cons(-1000000001, 1000000001) {}
};
bool operator<(Segment a, Segment b) { return a.bounds < b.bounds; }
int get(Segment a, Segment b) {
  if (b.bounds.first < a.cons.first) return 0;
  if (b.bounds.second > a.cons.second) return 0;
  return min(best[a.id], min(b.bounds.second, a.bounds.second) -
                             max(b.bounds.first, a.bounds.first));
}
void dump(Segment s) {
  printf("(%d)[%d %d]", _S[s.id].first, s.bounds.first, s.bounds.second);
}
int main() {
  int N, T;
  scanf("%d%d", &N, &T);
  for (int i = 0; i < (N); ++i) {
    scanf("%d%d%d", &_S[i].first, &_S[i].second.first, &_S[i].second.second);
    _S[i].first = T - _S[i].first;
  }
  _S[N++] = make_pair(0, pair<int, int>(-1000000001, 1000000001));
  _S[N++] = make_pair(T, pair<int, int>(-1000000001, 1000000001));
  sort(_S, _S + N);
  for (int i = 0; i < (N); ++i) S[i] = _S[i].second;
  set<Segment> ints;
  ints.insert(Segment(0));
  best[0] = 2000000000;
  for (int i = (1); i < (N); ++i) {
    Segment s(i);
    if (0) {
      printf("Segment: ");
      dump(s);
      printf("\n");
      printf("Contents: ");
      for (__typeof((ints).begin()) it = (ints).begin(); it != (ints).end();
           ++it) {
        dump(*it);
        printf(" ");
      }
      printf("\n");
    }
    set<Segment>::iterator fi = ints.lower_bound(s);
    if (fi != ints.begin()) --fi;
    if (fi->bounds.second < S[i].first) ++fi;
    set<Segment>::iterator it = fi;
    do {
      best[i] = max(best[i], get(*it, s));
      ++it;
    } while (it != ints.end() && it->bounds.first <= S[i].second);
    if (fi->bounds.second > S[i].second) {
      Segment tmp = *fi;
      Segment tmp2 = tmp;
      ints.erase(fi);
      tmp.bounds.second = tmp.cons.second = S[i].first;
      if (tmp.bounds.first != tmp.bounds.second) ints.insert(tmp);
      tmp2.bounds.first = tmp2.cons.first = S[i].second;
      if (tmp2.bounds.first != tmp2.bounds.second) ints.insert(tmp2);
    } else {
      set<Segment>::iterator la = fi;
      ++la;
      while (true) {
        set<Segment>::iterator it = la;
        ++it;
        if (it != ints.end() && it->bounds.first <= S[i].second) {
          ints.erase(la);
          la = it;
        } else
          break;
      }
      Segment tmp = *fi;
      ints.erase(fi);
      if (tmp.bounds.second > S[i].first)
        tmp.bounds.second = tmp.cons.second = S[i].first;
      if (tmp.bounds.first != tmp.bounds.second) ints.insert(tmp);
      Segment tmp2 = *la;
      ints.erase(la);
      if (tmp2.bounds.first < S[i].second)
        tmp2.bounds.first = tmp2.cons.first = S[i].second;
      if (tmp2.bounds.first != tmp2.bounds.second) ints.insert(tmp2);
    }
    ints.insert(s);
  }
  printf("%d\n", best[N - 1]);
}
