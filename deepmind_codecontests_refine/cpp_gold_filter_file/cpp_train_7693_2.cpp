#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
struct UF
{
	vector<int>v;
	UF():v(100,-1){};
	int R(int x){return v[x]<0?x:v[x]=R(v[x]);}
	int U(int x,int y)
	{
		x=R(x);
		y=R(y);
		if(x-y)
		{
			if(v[x]<v[y])swap(x,y);
			v[y]+=v[x];
			v[x]=y;
		}
		return x-y;
	}
};
double F(double x){return x*x;}
struct S{double d;int a,b;S(double d,int a,int b):d(d),a(a),b(b){}bool operator<(const S&s)const{return d<s.d;}};
int main()
{
	int n,i,j;
	double x[100],y[100],z[100],r[100],d,res;
	while(scanf("%d",&n),n)
	{
		vector<S>v;
		UF uf;
		for(i=0;i<n;++i)scanf("%lf%lf%lf%lf",x+i,y+i,z+i,r+i);
		for(i=0;i<n;++i)for(j=i+1;j<n;++j)
		{
			d=sqrt(F(x[i]-x[j])+F(y[i]-y[j])+F(z[i]-z[j]))-r[i]-r[j];
			if(d<0)uf.U(i,j);
			else v.push_back(S(d,i,j));
		}
		sort(v.begin(),v.end());
		res=0;
		for(i=0;i<v.size();++i)
		{
			S s=v[i];
			if(uf.U(s.a,s.b))res+=s.d;
		}
		printf("%.3f\n",res);
	}
	return 0;
}