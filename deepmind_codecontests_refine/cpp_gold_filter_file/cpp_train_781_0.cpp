#include <bits/stdc++.h>
using namespace std;
const int NMAX = 150005;
int N, Q, K;
struct st {
  int val, ind;
};
st v[NMAX];
int AIB[NMAX], D[NMAX], is_on[NMAX];
bool cmp(struct st a, struct st b) { return a.val > b.val; }
int zero(int x) { return (x ^ (x - 1)) & x; }
void update(int x, int val) {
  for (int i = x; i <= N; i += zero(i)) AIB[i] += val;
}
int suma(int x) {
  int rez = 0;
  for (int i = x; i > 0; i -= zero(i)) rez += AIB[i];
  return rez;
}
int main() {
  cin >> N >> K >> Q;
  for (int i = 1; i <= N; ++i) {
    cin >> v[i].val;
    v[i].ind = i;
  }
  sort(v + 1, v + N + 1, cmp);
  for (int i = 1; i <= N; ++i) D[v[i].ind] = i;
  int tip, id;
  for (int i = 1; i <= Q; ++i) {
    cin >> tip >> id;
    if (tip == 1) {
      is_on[id] = 1;
      update(D[id], 1);
    } else {
      if (!is_on[id])
        cout << "NO\n";
      else if (suma(D[id]) <= K)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
