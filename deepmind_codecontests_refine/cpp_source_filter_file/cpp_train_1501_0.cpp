#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000LL, INF2 = INF * INF;
struct node {
  vector<int> v;
  bool odw;
  long long a, b;
};
node tab[100005];
long long nwd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return nwd(b % a, a);
}
long long SUMA;
void dfs(int a) {
  if (tab[a].odw) return;
  tab[a].odw = true;
  tab[a].b = 1;
  long long mini = INF, ile = 0;
  for (__typeof((tab[a].v).begin()) it = ((tab[a].v).begin());
       it != (tab[a].v).end(); ++it)
    if (!tab[*it].odw) {
      dfs(*it);
      tab[a].b = tab[a].b / nwd(tab[a].b, tab[*it].b);
      if ((INF2 / tab[*it].b) < tab[a].b) {
        cout << SUMA << "\n";
        exit(0);
      }
      tab[a].b *= tab[*it].b;
      mini = min(mini, tab[*it].a);
      ile++;
    }
  if (tab[a].a == 0) {
    tab[a].a = ile * (mini / tab[a].b) * tab[a].b;
    tab[a].b *= ile;
  }
  if (tab[a].a == 0) {
    cout << SUMA << "\n";
    exit(0);
  }
}
void jebaj() {
  int n;
  long long ile_lisci = 0;
  cin >> n;
  for (int i = (0); i <= ((n)-1); ++i) {
    cin >> tab[i + 1].a;
    SUMA += tab[i + 1].a;
  }
  for (int i = (0); i <= ((n - 1) - 1); ++i) {
    int a, b;
    cin >> a >> b;
    tab[a].v.push_back(b);
    tab[b].v.push_back(a);
  }
  for (int i = (2); i <= (n); ++i) {
    if ((int)((tab[i].v).size()) == 1 && tab[i].a == 0) {
      cout << SUMA << "\n";
      return;
    }
  }
  dfs(1);
  cout << SUMA - tab[1].a << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  t = 1;
  for (int i = (0); i <= ((t)-1); ++i) {
    jebaj();
  }
}
