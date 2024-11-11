#include<bits/stdc++.h>
using namespace std;
int n,k,arr[200001];

int main()
{  cin>>n>>k;

    for(int i=0;i<n;i++)
    {
    	cin>>arr[i+1];
    	arr[i+1]+=arr[i];
	}
	int sum=0;
	for(int i=k;i<=n;i++)
	{ sum=max(sum,arr[i]-arr[i-k]);
		}
	  
		cout << fixed << setprecision(9) << (double)(sum+k)/2.0;
 
}