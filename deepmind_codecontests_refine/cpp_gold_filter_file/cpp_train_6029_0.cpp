#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;

  while(cin>>n,n){
	int sum=0;
	int temp;
	for(int i=0;i<n/4;++i){
	  cin>>temp;
	  sum+=temp;
	}
	cout<<sum<<endl;
  }

}

