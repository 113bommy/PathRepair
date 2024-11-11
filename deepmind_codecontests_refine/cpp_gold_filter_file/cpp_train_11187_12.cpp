#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int N, K, pos_max, pos_min, D, maxim, minim, Dmin, cnt;
int a, b;
int A[MAXN];
vector<pair<int, int> > Ans;
void Get_Pos() {
  maxim = -1;
  minim = 100005;
  for (int i = 1; i <= N; ++i) {
    if (A[i] > maxim) {
      maxim = A[i];
      pos_max = i;
    }
    if (A[i] < minim) {
      minim = A[i];
      pos_min = i;
    }
  }
}
int main() {
  cin >> N >> K;
  maxim = -1;
  minim = 100005;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  for (int k = 1; k <= K; ++k) {
    Get_Pos();
    if (minim == maxim) {
      Dmin = 0;
      break;
    }
    A[pos_max]--;
    A[pos_min]++;
    ++cnt;
    Ans.push_back(make_pair(pos_max, pos_min));
  }
  Get_Pos();
  Dmin = A[pos_max] - A[pos_min];
  cout << Dmin << " " << cnt << '\n';
  for (vector<pair<int, int> >::iterator it = Ans.begin(); it != Ans.end();
       ++it) {
    cout << it->first << " ";
    cout << it->second << " ";
    cout << '\n';
  }
  return 0;
}
