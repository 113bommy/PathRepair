#include<bits/stdc++.h>
using namespace std;
long long DP[2020][2020];
pair<long long,int> C[2020];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>C[i].first;
		C[i].second=i;
	}
	sort(C,C+N);
	reverse(C,C+N);
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
		{
			int k=i-j;
			DP[j+1][k]=max(DP[j+1][k],DP[j][k]+C[i].first*(C[i].second-j));
			DP[j][k+1]=max(DP[j][k+1],DP[j][k]+C[i].first*(N-C[i].second-1-k));
		}
	long long Ans=0;
	for(int i=0;i<=N;i++)
		Ans=max(Ans,DP[i][N-i]);
	cout<<Ans<<endl;
	return 0;
}
