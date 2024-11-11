#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <fstream>
#include <cmath>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define ITER(c) __typeof((c).begin())
#define PB(e) push_back(e)
#define FOREACH(i, c) for(ITER(c) i = (c).begin(); i != (c).end(); ++i)
#define MP(a, b) make_pair(a, b)
#define PARITY(n) ((n) & 1)

typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-10;

int N;
int table[20];
int reserv[210];

void dfs(int task, int pos, int &res){
  // cout << task << " "<< pos << " " << res << endl;
  if(pos + N >= res) return ;
  if(task == 10){
    res = min(pos + N, res);
    return;
  }
  
  for(int npos = pos; npos <= pos + N; npos++){
    bool ok = true;
    REP(j, N)if(reserv[npos + j] & table[j]){
      ok = false;
      break;
    }
    if(ok){
      REP(j, N) reserv[npos + j] |= table[j];
      dfs(task + 1, npos, res);
      REP(j, N) reserv[npos + j] ^= table[j];
    }
  }
}

int main(){
  while(cin >> N, N){
    string str;
    memset(table, 0, sizeof(table));
    memset(reserv, 0, sizeof(reserv));
    
    REP(i, 5){
      cin >> str;
      REP(j, N) if(str[j] == 'X') table[j] |= (1 << i);
    }
    REP(i, N) reserv[i] = table[i];
    int res = INF;
    dfs(1, 0, res);
    cout << res << endl;
  }
  return 0;
}