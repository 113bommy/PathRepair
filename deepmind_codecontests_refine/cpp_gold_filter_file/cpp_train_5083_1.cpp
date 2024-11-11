#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<22;
typedef long long ll;
typedef unsigned long long ull;
int data[maxn][21],n,k;
int mem[maxn*2];
char s[maxn];
int mx=1000000000,mxl=0;
void update(int sta,int nums,int len) {
    mem[sta|(1<<len)]+=nums;
    if(mem[sta|(1<<len)]>=k)
        if(mxl<len)mxl=len,mx=sta;
        else if(mxl==len)mx=min(mx,sta);

}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++) {
        scanf("%s",s);//len=2^i
        for(int j=0;j<(1<<i);j++) {
            int tmp=j;
            tmp|=1<<i;
            data[tmp][0]+=(s[j]=='1');
        }
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<(1<<(n+1));j++) {
            if(!data[j][i])continue;//t-s
            ull s=j&((1<<i)-1),t=j>>i;int l=(32-__builtin_clz(t))-1;//有t多少位
            if(i)update(s,data[j][i],i);
            if(!l){continue;}
            t^=(1<<l);
            int first1=(32-(t?__builtin_clz(t):32));
            unsigned int num=t<<(32-l);
            int first0=l?(l-((~num)?__builtin_clz(~num):l)):0;
            int newt,news;
            if(first1>0){
                newt=t&((1<<first1)-1);
                newt|=(1<<first1-1);
                news=(s<<1)|1;
                data[(newt<<(i+1))|news][i+1]+=data[j][i];
            }
            if(first0>0){
                newt=t&((1<<first0)-1);
                newt|=(1<<first0-1);
                news=(s<<1);
                data[(newt<<(i+1))|news][i+1]+=data[j][i];
            }
        }
    }
    if(mx==1000000000){puts("");return 0;}
    for(int i=mxl;i>=1;i--) {
        printf("%d",(mx&(1<<i-1))?1:0);
    }
    printf("\n");
    return 0;
}