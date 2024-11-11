//{ PXH612
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int,int>
#define x first
#define y second

ll in() {ll x=0;int o=0,c=char();for(;!isdigit(c);c=getchar()) o=c=='-';for(;isdigit(c);c=getchar()) x=x*10+c-'0';return o?-x:x;}
char inchar() {char c=getchar();while(c==' '||c=='\n') c=getchar();return c;}
#define in in()
#define inchar inchar()

#define FOR(i,a,b) for(int i=a,_=b;i<=_;i++)
#define ROF(i,a,b) for(int i=b,_=a;_<=i;i--)
#define FR(i,n) FOR(i,1,n)
#define RR(x,a,b) {cout<<#x<<": ";FOR(__,a,b) cout<<x[__]<<" ";cout<<"\n";}
#define rr(x) " "<<#x<<'='<<(x)<<" "

template<typename A,typename B>A min(A a,B b){return a<b?a:b;}
template<typename A,typename B>A max(A a,B b){return a>b?a:b;}
template<typename A,typename B>bool Min(A &a,B b){if(a<b) return 0;a=b;return 1;}
template<typename A,typename B>bool Max(A &a,B b){if(a>b) return 0;a=b;return 1;}

#define VEC(i,a) for(auto&i:a)
#define pb push_back
#define vall(a) a.begin(),a.end()
#define fiv(a) (int)a.size()-1

#define bit(x,i) ((x>>(i-1))&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define mu2(x) (1ll<<x)
#define bitnum(x) __builtin_popcountll(x)

#define freopen(x,o) freopen(x".inp","r",stdin);if(o) freopen(x".out","w",stdout);
#define false(x) if(!(x))
#define middle(a,b) (a+(b-(a))/2)
#define memset(x,a) memset(x,a,sizeof x)
//}

const int N=1e6+5;
int n,q;
string s[N];

int t[N][30],w[N][30],T;
int sum[N][30][30];
int intc(char c)
{
    if(c=='#') return 0;
    return c-'a'+1;
}
void ADD_TRIE(int S)
{
    int x=0;
    FOR(i,0,fiv(s[S]))
    {
        int c=intc(s[S][i]);
        if(t[x][c]==0) t[x][c]=++T;
        w[x][c]++;

        x=t[x][c];
    }
}

void BIL_TRIE(int S)
{
    int x=0;
    FOR(i,0,fiv(s[S]))
    {
        int c=intc(s[S][i]);
        FOR(i,0,26) if(t[x][i]) sum[S][c][i]+=w[x][i];

        x=t[x][c];
    }
}
main()
{
   // freopen("hz",0);
    n=in;
    FOR(i,1,n) cin>>s[i],s[i]+='#';
    FOR(i,1,n) ADD_TRIE(i);
    FOR(i,1,n) BIL_TRIE(i);
    FOR(i,1,in)
    {
        int k=in;string a;

        ll res=0;
        cin>>a;a="#"+a;
        FOR(i,0,fiv(a)) FOR(j,0,i-1) res+=sum[k][intc(a[i])][intc(a[j])];
        cout<<res+1<<"  \n";
    }
}
