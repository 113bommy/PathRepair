#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M;
int when[100002];
set<pair<int, int> > L;
set<pair<int, int> > S;
vector<pair<int, int> > V;
vector<int> D;
int ARB1[4 * 100002], ARB2[4 * 100002], Ap, Av, A1, A2, Ar;
void update(int *ARB, int nod, int s1, int s2) {
  if (s1 == s2) {
    ARB[nod] = Av;
    return;
  }
  int mid = (s1 + s2) / 2;
  if (Ap <= mid)
    update(ARB, nod * 2, s1, mid);
  else
    update(ARB, nod * 2 + 1, mid + 1, s2);
  ARB[nod] = max(ARB[nod * 2], ARB[nod * 2 + 1]);
}
void query(int *ARB, int nod, int s1, int s2) {
  if (A1 <= s1 && s2 <= A2) {
    Ar = max(Ar, ARB[nod]);
    return;
  }
  int mid = (s1 + s2) / 2;
  if (A1 <= mid) query(ARB, nod * 2, s1, mid);
  if (A2 > mid) query(ARB, nod * 2 + 1, mid + 1, s2);
}
int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos, val;
      cin >> pos >> val;
      val -= i;
      when[pos] = i;
      V.clear();
      for (set<pair<int, int> >::iterator it = S.begin(); it != S.end(); ++it)
        if (it->first < val) {
          Ap = it->second, Av = 0;
          update(ARB1, 1, 1, N);
          V.push_back(*it);
        } else
          break;
      V.push_back(make_pair(val, pos));
      sort(V.begin(), V.end());
      S.insert(make_pair(val, pos));
      L.insert(make_pair(pos, val));
      for (int j = int(V.size()) - 1; j >= 0; --j) {
        A1 = V[j].second, A2 = N, Ar = 0;
        query(ARB1, 1, 1, N);
        Ap = V[j].second, Av = Ar + 1;
        update(ARB1, 1, 1, N);
        Ap = -V[j].first + 10, Av = Ar + 1;
        update(ARB2, 1, 1, N + 10);
      }
    } else {
      int wh;
      cin >> wh;
      int count = 0;
      V.clear();
      for (set<pair<int, int> >::iterator it = L.begin(); it != L.end(); ++it) {
        ++count;
        if (wh == count) {
          Ap = it->first, Av = 0;
          update(ARB1, 1, 1, N);
          Ap = -it->second + 10, Av = 0;
          update(ARB2, 1, 1, N + 10);
          S.erase(make_pair(it->second, it->first));
          L.erase(it);
          break;
        }
        Ap = -it->second + 10, Av = 0;
        update(ARB2, 1, 1, N + 10);
        V.push_back(*it);
      }
      for (int j = int(V.size()) - 1; j >= 0; --j) {
        A1 = 1, A2 = -V[j].second + 10, Ar = 0;
        query(ARB2, 1, 1, N + 10);
        Ap = V[j].first, Av = Ar + 1;
        update(ARB1, 1, 1, N);
        Ap = -V[j].second + 10, Av = Ar + 1;
        update(ARB2, 1, 1, N + 10);
      }
    }
    cout << max(0, ARB1[1]) << '\n';
  }
}
