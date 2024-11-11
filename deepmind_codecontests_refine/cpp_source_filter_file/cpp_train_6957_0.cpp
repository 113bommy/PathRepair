#include <bits/stdc++.h>
using namespace std;

int main() {

	int a,b;
	cin>>a>>b;
	if(b<10){a=a*10+b;}
  else if(b<100){a=a*100+b;}
  else{a=a*1000+b;}
  if(fmod(sqrt(a),1)%1==0){cout<<"Yes"<<endl;}
	else{cout<"No"<<endl;}
}
