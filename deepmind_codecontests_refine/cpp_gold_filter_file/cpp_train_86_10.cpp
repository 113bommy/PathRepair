#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
  	cin>>a>>b>>c;
  	cout<< ((a+c==b || b+c==a || a+b==c)? "Yes":"No")<<endl;
	return 0;
}
