#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 17, INF = 0x3f3f3f3f;
vector<pair<int, int> > V[MAX];
int dokr[MAX], odpoc[MAX];
int odakle[MAX], ukdulj[MAX];
long long setd[MAX];
int bio[MAX];
int n;
set<pair<long long, int> > S;
void BfsPoc(int poc, int polje[MAX], int bitna0) {
  deque<int> Q;
  for (int i = 0; i < MAX; i++) polje[i] = INF;
  memset(setd, -1, sizeof setd);
  memset(bio, 0, sizeof bio);
  polje[poc] = 0;
  setd[poc] = 0;
  S.insert(pair<int, int>(0, poc));
  for (; !S.empty();) {
    int tmp = S.begin()->second;
    S.erase(S.begin());
    if (bio[tmp]) continue;
    bio[tmp] = 1;
    for (int i = 0; i < (int)V[tmp].size(); i++) {
      pair<int, int> nn = V[tmp][i];
      int ndist = polje[tmp];
      if (ndist || !bitna0 || nn.second) ndist++;
      if (polje[nn.first] > ndist) {
        polje[nn.first] = ndist;
        if (!ndist && bitna0) {
          odakle[nn.first] = tmp;
          ukdulj[nn.first] = ukdulj[tmp] + 1;
        }
      }
      if (polje[nn.first] == ndist) {
        if (bitna0 &&
            (ukdulj[nn.first] == -1 || ukdulj[nn.first] > ukdulj[tmp] + 1)) {
          ukdulj[nn.first] = ukdulj[tmp] + 1;
          odakle[nn.first] = tmp;
        }
      }
      long long nset = (long long)ndist * MAX + ukdulj[nn.first];
      if (setd[nn.first] == -1) {
        S.insert(pair<int, int>(nset, nn.first));
        setd[nn.first] = nset;
      } else if (setd[nn.first] > nset) {
        S.erase(pair<int, int>(setd[nn.first], nn.first));
        S.insert(pair<int, int>(nset, nn.first));
        setd[nn.first] = nset;
      }
    }
  }
  ukdulj[poc] = -1;
}
void NadiPut() {
  int da = 0;
  int done = 0;
  vector<int> Node[2];
  memset(bio, 0, sizeof bio);
  int best = dokr[0];
  for (int i = 0; i < n; i++)
    if (!dokr[i]) Node[0].push_back(i);
  for (int ind = 0;; ind ^= 1) {
    int minn = INF;
    Node[1 ^ ind].clear();
    for (int i = 0; i < (int)Node[ind].size(); i++) {
      int tmp = Node[ind][i];
      if (!tmp) {
        done = 1;
        break;
      }
      for (int j = 0; j < (int)V[tmp].size(); j++) {
        pair<int, int> nn = V[tmp][j];
        if (best == odpoc[nn.first] + dokr[nn.first] &&
            dokr[nn.first] > dokr[tmp])
          minn = min(minn, nn.second);
      }
    }
    if (done) break;
    for (int i = 0; i < (int)Node[ind].size(); i++) {
      int tmp = Node[ind][i];
      for (int j = 0; j < (int)V[tmp].size(); j++) {
        pair<int, int> nn = V[tmp][j];
        if (best == odpoc[nn.first] + dokr[nn.first] &&
            dokr[nn.first] > dokr[tmp] && nn.second == minn) {
          if (!bio[nn.first] || ukdulj[odakle[nn.first]] > ukdulj[tmp] + 1) {
            odakle[nn.first] = tmp;
            ukdulj[nn.first] = ukdulj[tmp] + 1;
            if (!bio[nn.first]) {
              Node[1 ^ ind].push_back(nn.first);
              bio[nn.first] = 1;
            }
          }
        }
      }
    }
    da = 1;
    printf("%d", minn);
  }
  if (!da) printf("0");
  printf("\n");
  vector<int> R;
  for (int poz = 0; poz != n - 1; poz = odakle[poz]) R.push_back(poz);
  R.push_back(n - 1);
  printf("%d\n", (int)R.size());
  for (int i = 0; i < (int)R.size(); i++) printf("%d ", R[i]);
  printf("\n");
}
int main() {
  int m;
  memset(odakle, -1, sizeof odakle);
  memset(ukdulj, -1, sizeof ukdulj);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    V[a].push_back(pair<int, int>(b, c));
    V[b].push_back(pair<int, int>(a, c));
  }
  BfsPoc(0, odpoc, 0);
  BfsPoc(n - 1, dokr, 1);
  NadiPut();
  return 0;
}
