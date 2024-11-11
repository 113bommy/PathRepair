#include <cstdio>
using namespace std;

typedef long long ll;
typedef struct stick{
 ll lren, rren, sl, sr, weight; 
} STICK;

ll n, tmp, top;
ll depth[101];
STICK st[101];

void init(ll k){
 for(ll i = 0; i <= k; i++){
  depth[i] = 0;
  st[i].weight = 0;
 }
}

ll gcd(ll a, ll b){
 if(b == 0) return a;
 return gcd(b, a % b);
}

ll lcm(ll a, ll b){
 return a * b / gcd(a, b);
}

ll solve(ll k){
 if(st[k].weight > 0) return st[k].weight;
 if(st[k].sl == 0 && st[k].sr == 0){
  return st[k].weight = st[k].lren + st[k].rren;
 }else if(st[k].sl == 0){
  return st[k].weight = solve(st[k].sr) * (st[k].lren + st[k].rren) / gcd(solve(st[k].sr), st[k].lren);
 }else if(st[k]. sr == 0){
  return st[k].weight = solve(st[k].sl) * (st[k].lren + st[k].rren) / gcd(solve(st[k].sl), st[k].rren);
 }else {
  tmp = lcm(solve(st[k].sl) * st[k].lren, solve(st[k].sr) * st[k].rren);
  return st[k].weight = tmp / st[k].lren + tmp / st[k].rren;
 }
}

ll main(){
 while(scanf("%d", &n)){
  if(n == 0) break;
  init(n);
  for(ll i = 1; i <= n; i++){
   scanf("%d %d %d %d", &st[i].lren, &st[i].rren, &st[i].sl, &st[i].sr);
   tmp = gcd(st[i].lren, st[i].rren);
   st[i].lren /= tmp;
   st[i].rren /= tmp;
  }
  for(ll i = 1; i <= n; i++){
   depth[st[i].sl]++;
   depth[st[i].sr]++;
  }
  for(ll i = 1; i<= n; i++){
   if(depth[i] == 0){
    top = i;
    break;
   }
  }
  printf("%d\n", solve(top));
 }
 return 0;
}