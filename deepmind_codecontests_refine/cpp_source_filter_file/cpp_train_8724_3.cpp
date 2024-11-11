#include<bits/stdc++.h>
using namespace std;

ll d[33];
int main()
{
int n,m,k,a,an=0;
cin>>n>>m;
for(int i=0;i<n;i++)
{cin>>k;
	while(k--)
	{cin>>a;d[a]++;}
}
for(int i=0;i<=m;i++)if(d[i]==n)an++;
cout<<an<<endl;

}

