#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n){
		if(n==0) break;
		int a[n], S[n], sum=0;
		for(int i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
			S[i]=sum;
		}

		long max=S[0];
		for(int i=0;i<n;++i){
			if(S[i]>max) max=S[i];
			for(int j=0;j<i+1;++j){
				if(S[i]-S[j]>max) max=S[i]-S[j];
			}
		}

		cout<<max<<endl;
	}

	return 0;