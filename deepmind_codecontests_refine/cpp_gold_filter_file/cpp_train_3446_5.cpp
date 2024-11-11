#include <bits/stdc++.h>
using namespace std;
long long int m[300000] = {};
long long int LT[600010] = {};
pair<pair<long long int, long long int>, pair<long long int, long long int> >
    scenery[300000] = {};
int N, P, i, a, b;
int comparison_by_id(const void *a, const void *b) {
  if ((((pair<pair<long long int, long long int>,
              pair<long long int, long long int> > *)(a))
           ->first.first) < (((pair<pair<long long int, long long int>,
                                    pair<long long int, long long int> > *)(b))
                                 ->first.first))
    return -1;
  else
    return 1;
}
void sort_by_id() {
  qsort(scenery, P,
        sizeof(pair<pair<long long int, long long int>,
                    pair<long long int, long long int> >),
        comparison_by_id);
}
int comparison_by_ab(const void *a, const void *b) {
  if (((pair<pair<long long int, long long int>,
             pair<long long int, long long int> > *)(a))
          ->second.second < ((pair<pair<long long int, long long int>,
                                   pair<long long int, long long int> > *)(b))
                                ->second.second)
    return -1;
  else if (((pair<pair<long long int, long long int>,
                  pair<long long int, long long int> > *)(a))
               ->second.second >
           ((pair<pair<long long int, long long int>,
                  pair<long long int, long long int> > *)(b))
               ->second.second)
    return 1;
  else {
    if (((pair<pair<long long int, long long int>,
               pair<long long int, long long int> > *)(a))
            ->second.first < ((pair<pair<long long int, long long int>,
                                    pair<long long int, long long int> > *)(b))
                                 ->second.first)
      return -1;
    else if (((pair<pair<long long int, long long int>,
                    pair<long long int, long long int> > *)(a))
                 ->second.first ==
             ((pair<pair<long long int, long long int>,
                    pair<long long int, long long int> > *)(b))
                 ->second.first)
      return 0;
    else
      return 1;
  }
}
void sort_by_ab() {
  qsort(scenery, P,
        sizeof(pair<pair<long long int, long long int>,
                    pair<long long int, long long int> >),
        comparison_by_ab);
}
void naively_solve(int id) {
  long long int ans = 0;
  for (int j = scenery[id].second.first; j < N; j += scenery[id].second.second)
    ans += m[j];
  scenery[id].first.second = ans;
}
void dynamically_solve(int begin, int end) {
  int H = end;
  int B = scenery[begin].second.second;
  int y = N - 1;
  for (; y >= 0; y--) {
    LT[y] = m[y] + LT[y + B];
    while (y == scenery[H].second.first && H >= begin) {
      scenery[H].first.second = LT[y];
      H--;
    }
    if (H < begin) break;
  }
}
void read_data() {
  cin >> N;
  for (i = 0; i < N; i++) cin >> m[i];
  cin >> P;
  pair<long long int, long long int> temp;
  for (i = 0; i < P; i++) {
    cin >> a >> b;
    scenery[i].first.first = i;
    scenery[i].first.second = -1;
    scenery[i].second.first = a - 1;
    scenery[i].second.second = b;
  }
}
void output_ans() {
  int j = 0;
  for (j = 0; j < P; j++) cout << scenery[j].first.second << endl;
}
int main() {
  read_data();
  sort_by_ab();
  int B = 0, E = 0, i = 0, j;
  while (scenery[B].second.second < 500 && i < P) {
    while (scenery[B].second.second == scenery[i].second.second && i < P) i++;
    dynamically_solve(B, i - 1);
    B = i;
  }
  for (; i < P; i++) naively_solve(i);
  sort_by_id();
  output_ans();
  return 0;
}
