#include<iosstream>
using namespace std;
int a[100005];
int main()
{	int N,K,Q,m;
	cin>>N>>K>>Q;
	for(int i=0;i<Q;i++)
	{
		cin>>m;
		a[m]++;
	}
	for(int i=1;i<=N;i++)
	{
		if(Q-a[i]>=K)
		{
			cout<<"No"<<endl;
		}
			
		else
		{
			cout<<"Yes"<<endl;
		}
			
	}
}
