#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long k,a,b,c=0;
    cin>>k>>a>>b;
    if(a>=k)
    {
        cout<<1<<endl;
        return 0;
    }else if(b>=a){
    	cout<<-1<<endl;
        return 0;
	}else if((k-a)%(a-b)>=1){
    	c=1;
	}
    cout<<((k-a)/(a-b)+c)*2+1<<endl;
}