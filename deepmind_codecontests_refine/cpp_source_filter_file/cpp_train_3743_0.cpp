#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
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

void shift(int &a, int &b, int &c, int &d){
  int tmp = a;
  a = b;
  b = c;
  c = d;
  d = tmp;
}

void rotx(vector<int> &v){
  shift(v[0], v[1], v[2], v[3]);
  shift(v[4], v[5], v[6], v[7]);
}

void roty(vector<int> &v){
  shift(v[0], v[1], v[5], v[4]);
  shift(v[6], v[7], v[3], v[2]);
}

void rotz(vector<int> &v){
  shift(v[0], v[4], v[7], v[3]);
  shift(v[1], v[2], v[6], v[5]);
}

vector<int> normalize(vector<int> v){
  vector<int> res = v;
  REP(i, 4){
    REP(j, 4){
      REP(k, 4){
        res = min(res, v);
        rotx(v);
      }
      roty(v);
    }
    rotx(v);
  }
  return res;
}

int main(){
  string line;
  while(getline(cin, line)){
    string tmp;
    istringstream in(line);

    int cc = 0;
    map<string, int> color;
    vector<int> v;
    
    while(in >> tmp){
      if(color.find(tmp) == color.end()) color[tmp] = cc++;
      v.push_back(color[tmp]);
    }
    
    vector<int> p(7);
    REP(i, 7) p[i] = i;

    set<vector<int > > oct_set;
    
    do{
      vector<int> oct(8);
      oct[7] = v[7];
      REP(i, 7) oct[p[i]] = v[i];
      oct_set.insert(normalize(oct));
    }while(next_permutation(ALL(p)));
    a
    cout << oct_set.size() << endl;
  }
  return 0;
}