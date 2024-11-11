#include <iostream>
#include <string>
using namespace std;
int main(){

	string str,JOI="JOI",IOI="IOI";
	while(cin>>str){
	int J=0,I=0,c1=0,c2=0,a=-1,b=-1;
	for(int i=0;i<str.size();i++){
		J=str.find(JOI,i);
		I=str.find(IOI,i);
		if(J>=0&&J!=a){
			c1++;
			a=J;
		}
		if(I>=0&&I!=b){
			c2++;
			b=I;
		}
	}
	cout<<c1<<endl<<c2<<endl;
	}
return 0;
}