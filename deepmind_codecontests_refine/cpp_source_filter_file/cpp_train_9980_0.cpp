#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;

int main()
{
  int H, W, N;
  vector< pair< int, int > > g[200000];
  bool v[200000] = {};
  int64 cost[200000];

  scanf("%d %d", &H, &W);
  scanf("%d", &N);
  while(N--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    --x, --y;
    g[x].emplace_back(H + y, z);
    g[H + y].emplace_back(x, z);
  }

  for(int i = 0; i < H + W; i++) {
    if(v[i]) continue;

    queue< int > que;
    int L = INF, R = INF;
    que.emplace(i);
    v[i] = true;
    cost[i] = 0;

    while(!que.empty()) {
      int idx = que.front();
      que.pop();
      if(idx < H) L = min(L, cost[idx]);
      else R = min(R, cost[idx]);
      for(auto& e : g[idx]) {
        if(v[e.first]++) {
          if(cost[idx] + cost[e.first] != e.second) {
            puts("No");
            return (0);
          }
        } else {
          que.emplace(e.first);
          cost[e.first] = e.second - cost[idx];
        }
      }
    }
    if(L + R < 0) {
      puts("No");
      return (0);
    }
  }

  puts("Yes");
}
