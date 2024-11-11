#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<bitset>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
bitset<2010>f[2010],g[2010],p[2010];
char ss[2010];
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n=read();
    for(int i=2;i<=n;i++)
    {
    	scanf("%s",ss+1);
    	for(int j=1;j<i;j++)
    	{
    		if(ss[j]=='0')p[j][i]=1;
    		else p[i][j]=1;
    	}
    }
    for(int i=1;i<=n;i++)f[i][i]=1,g[i][i]=1;
    for(int d=2;d<=n;d++)
    {
    	for(int l=1;l+d-1<=n;l++)
    	{
    		int r=l+d-1;
    		g[r][l]=(g[r]&f[l+1]&p[l]).any();
    		f[l][r]=(f[l]&g[r-1]&p[r]).any();
    	}
    }
    pr2((g[n]&f[1]).count());
    return 0;
}