#include <iostream>
using namespace std;

int V, E, R, S[500010], T[500010], D[500010];
int C[100010];

const int Inf = 10000*100000+100;

int main() {
  cin >> V >> E >> R;
  for (int i=0;i<E;++i)
    cin >> S[i] >> T[i] >> D[i];
  for (int i=0;i<V;++i) {
    if (i==R)
      C[i] = 0;
    else
      C[i] = Inf;
  }
  for (int t=0;t<V;++t) {
    bool update = false;
    for (int i=0;i<E;++i) {
      int s = S[i], t = T[i], d = D[i];
      if (C[s]<Inf && C[s]+D[i]<C[t]) {
	C[t] = C[s]+D[i];
	update = true;
      }
    }
    if (!update) break; // 辺を一巡して更新がなければ打ち切って良い
  }
  for (int i=0;i<V;++i) {
    if (C[i]==Inf)
      cout << "INF" << endl;
    else
      cout << C[i] << endl;
  }
}