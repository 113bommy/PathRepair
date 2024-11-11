#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int a,b,c,d,e,f;
	int maxs=0,maxsl=0,svf=0
	double base=0;
	cin>>a>>b>>c>>d>>e>>f;
	for(int i=0;i<=f/(100*a)+1;i++)
	{
		for(int j=0;j<=f/(100*b)+1;j++)
		{
			for(int k=0;k<=f/c+1;k++)
			{
				for(int l=0;l<=f/d+1;l++)
				{

					double sol = k*c + l*d;
					double sv = 100*(a*i+b*j);

					if(sol+sv<=(double)f && !(i+j==0) && sol<=((a*i+b*j)*e))
					{
						if(base<=sol/sv)
						{
							base=sol+sv;
							maxs=100*(a*i+b*j)+k*c+l*d;
							mxsl=k*c+l*d;
						}
					}
				}
			}
		}
	}
	cout<<(long long)maxs<<" "<<(long long)maxsl<<"\n";
}