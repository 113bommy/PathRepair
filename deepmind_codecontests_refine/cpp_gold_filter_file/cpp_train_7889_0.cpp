#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
const int P = 1e9+7;
#define fr(i,low,up,st) for(register int i = low;i <= up;i += st)
#define nfr(i,low,up,st) for(register int i = low;i >= up;i -= st)
#define size(a) a.size()
#define fill(a,b) memset(a,b,sizeof a)

int fact[N],inv[N];

inline int pow_mod(int x,int k){
   int res = 1,base = x;
   while(k){
      if(k&1)res = 1LL*res*base%P;
      k >>= 1;
      base = 1LL*base*base%P;
   }
   return res;
}

void init(){
   fact[0] = inv[0] = 1;
   fr(i,1,N-1,1)fact[i] = 1LL*fact[i-1]*i%P;
   inv[N-1] = pow_mod(fact[N-1],P-2);
   nfr(i,N-2,1,1)inv[i] = 1LL*inv[i+1]*(i+1)%P;
}

inline int c(int n,int m){
   if(n < m)return 0;
   return 1LL*fact[n]*inv[n-m]%P*inv[m]%P;
}

void Mod(int &x){
   x = (x>=P)?x-P:x;
   x = (x<0)?x+P:x;
}
int n,m;
int calc(int up,int a,int b){
   int pans = 0;
   for(int k = 0;1LL*k*(b+1)+1LL*a*m <= up && k+m <= n; ++k){
      Mod(pans += 1LL*pow_mod(-1,k)*c(up-a*m-k*(b+1)+n,n)*c(n-m,k)%P);
   }
   //cerr << up <<' '<< a << ' ' << b <<' ' << pans << endl;
   return 1LL*pans*c(n,m)%P;
}

int solve(int up){
   int ans = 0;
   fr(i,1,up,1){
      Mod(ans += calc(up,i,i-1)-calc(up,i+1,i-1));
      //cerr << i <<' '<< ans << endl;
   }
   Mod(ans = c(up+n,n)-ans);
   return ans;
}

int main(){
   init();
   int L,R;
   scanf("%d%d%d%d",&n,&m,&L,&R);
   int fans = 0;
   Mod(fans = solve(R)-solve(L-1));
   printf("%d\n",fans);
   return 0;
}
