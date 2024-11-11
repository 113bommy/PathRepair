#include <bits/stdc++.h> 
#define MX 32
using namespace std; 
typedef long long int ll ;
typedef pair <ll , ll> P;
bool comp(P p,P q) { 
return p.second*q.first<q.second*p.first ; }
ll dp[MX];
int main() {
int n,T; 
scanf("%d %d",&n,&T); 
vector <int> all ; 
vector <P> vx; 
for(int i=0;i<n; i++) {
int a,b; 
scanf("%d %d",&a,&b); 
b++;
b+=a;
if (a==0) all.push_back(b);
else { 
vx.push_back(P(a,b)); } 
 }
 sort(vx.begin() ,vx.end() ,comp); 
for(int i=0;i<MX; i++) dp[i]=T+1;
dp[0]=0; 
for(int i=0;i<vx.size(); i++) { 
P p=vx[ i ];
 for(int j=MX-2;j>=0;j--) { 
 if (dp[ j]>T) continue; 
dp[j+1]=min(dp[ j+1],(p.first+1)*dp[ j]+p.second);
}
} 
sort(all.begin() ,all.end());
int ret=0; 
for(int i=0;i<MX; i++) {
  if (dp[ i]>T) continue; 
 ll zan=T-dp[ i ];
 int pos=0; 
 while(pos<all.size()&&zan>=all[pos]) { 
 zan-=all[pos];
  pos++; 
 } 
 ret=max(ret ,pos+i); 
 } 
 printf("%d\n",ret); 
return 0; 
}
