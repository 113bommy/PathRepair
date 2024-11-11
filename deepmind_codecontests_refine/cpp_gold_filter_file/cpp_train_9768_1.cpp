#include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double db;
const int oo=2139063143;
const int N=55;
const db eps=1e-7;
#define pritnf printf
//char buf[1<<22],*p1=buf,*p2=buf,obuf[1<<22],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void sc (T &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
template <typename T>
inline void print (T x)
{
    if (x< 0) putchar('-'),x=-x;
    if (x>=10) print(x/10);
    putchar(x%10+'0');
}
template <typename T>
inline void pr (T x) { print(x),putchar('\n'); }
template <typename T1,typename T2>
void chkmax (T1 &A,T2 B) { A=A>=B?A:B; }
template <typename T1,typename T2>
void chkmin (T1 &A,T2 B) { A=A<=B?A:B; }
struct LY { LL c; int w,las; }a[N];
int n,X,D,fa[N],m;
LL f[N*N*N];
void update (LL c,int w)
{
	for (int i=m; i>=w; i--)
		chkmin (f[i],f[i-w]+c);
}
int main ()
{
    // freopen (".in","r",stdin);
    // freopen (".out","w",stdout);
	sc(n),sc(X),sc(D);
	for (int i=1; i<=n; i++)
	{
		sc(a[i].c); a[i].w=1,a[i].las=i==1?1e9:D;
		if (i> 1) sc(fa[i]);
	}
	for (int i=n; i> 1; i--)
		a[fa[i]].c+=a[i].c,a[fa[i]].w+=a[i].w;
	m=n*n*n;
	memset (f,31,sizeof (LL)*(m+1));
	f[0]=0;
	int nd=min (n,D);
	for (int i=1; i<=n; i++)
	{
		int las=nd;
		for (int j=1; j<=las; j<<=1)
			update (a[i].c*j,a[i].w*j),las-=j;
		if (las) update (a[i].c*las,a[i].w*las);
	}
	sort (a+1,a+n+1,[](LY A,LY B) { return A.w*B.c> B.w*A.c; });
	int ans=0;
	for (int i=0; i<=m; i++) if (f[i]<=X)
	{
		int las=X-f[i],g=0;
		for (int j=1; j<=n; j++)
		{
			int h=min ((LL)a[j].las-nd,las/a[j].c);
			g+=h*a[j].w,las-=h*a[j].c;
		}
		chkmax (ans,i+g);
	}
	pr(ans);

    return 0;
}
