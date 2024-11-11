#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int N;
  	cin>>N;
  	bool flag = false;
  	for(int i=0;i<N;i++){
      string x;
      cin>>x;
      if(x=="Y")flag=true;
    }
  	cout<<flag?"four":"three"<<endl;
}