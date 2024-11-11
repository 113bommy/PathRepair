#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b=0,c=0;
	string d,e;
	cin >>a;
	for(int i=0;i<a;i++){
		cin>>d>>e;
		if(d.compare(e)>0)b=b+3;
		else if(d.compare(e)==0)b++;c++;
		else if(d.compare(e)<0)c=c+3;
	}
	cout <<b<<" "<<c<<endl;
	return 0;
}