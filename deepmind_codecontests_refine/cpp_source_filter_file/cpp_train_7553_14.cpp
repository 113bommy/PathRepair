#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 10;
struct Player {
  int pts;
  string name;
};
vector<Player> V;
int N, M;
int A[MAX], B[MAX];
string vasya;
int iv;
bool operator<(const Player &a, const Player &b) {
  return make_pair(-a.pts, a.name) < make_pair(-b.pts, b.name);
}
int getHighest() {
  int r = iv;
  Player t = V[iv];
  t.pts += B[0];
  int j = N - 1;
  for (int i = 0; i < iv; ++i) {
    Player cur = V[i];
    cur.pts += B[j];
    if (t < cur) {
      --r;
      ++j;
    }
  }
  return r;
}
int getLowest() {
  int r = iv;
  Player t = V[iv];
  t.pts += B[N - 1];
  int j = 0;
  for (int i = N - 1; i > iv; --i) {
    Player cur = V[i];
    cur.pts += B[j];
    if (cur < t) {
      ++r;
      --j;
    }
  }
  return r;
}
int main() {
  scanf("%d", &N);
  char str[40];
  V.assign(N, Player());
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%s %d", str, &x);
    V[i].pts = x;
    V[i].name = str;
  }
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    scanf("%d", B + i);
  }
  sort(B, B + M);
  reverse(B, B + M);
  scanf("%s", str);
  vasya = string(str);
  sort((V).begin(), (V).end());
  for (int i = 0; i < N; ++i) {
    if (V[i].name == vasya) iv = i;
  }
  for (typeof(V.begin()) it = V.begin(); it != V.end(); ++it)
    cerr << it->name << " " << it->pts << endl;
  cerr << "iv"
       << " = " << iv << endl;
  ;
  cout << getHighest() + 1;
  cout << " ";
  cout << getLowest() + 1;
  cout << endl;
  return 0;
}
