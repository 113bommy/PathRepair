#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair< int, int > Pi;

bool cmp(const pair< Pi, Pi >& p, const pair< Pi, Pi >& q)
{
  if(p.first.first + p.second.first, q.first.first + q.second.first)
    return(p.first.first + p.second.first < q.first.first + q.second.first);
  return(p.first.first * p.first.second + p.second.first * p.second.second <
         q.first.first * p.first.second + q.second.first * q.second.second);
}

// ax + by = d
pair< Pi, Pi > ask(int a, int b, int d)
{
  pair< Pi, Pi > ret({INF, INF}, {INF, INF});
  for(int x = 0; x < 10000; x++) {
    int f = abs(d - a * x);
    if(f % b == 0) ret = min(ret, {{x, a}, {f / b, b}}, cmp);
  }
  return(ret);
}

int main()
{
  int a, b, d;
  while(cin >> a >> b >> d, a) {
    auto alpha = ask(a, b, d), beta = ask(b, a, d);
    auto ret = min(alpha, beta, cmp);
    if(ret == beta) swap(ret.first, ret.second);
    cout << ret.first.first << " " << ret.second.first << endl;
  }
}