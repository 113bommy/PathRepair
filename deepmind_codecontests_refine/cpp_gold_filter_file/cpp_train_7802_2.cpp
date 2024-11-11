#include<string>
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int cnt=0;
		while(s.size()!=1){
			string t=s.substr(s.size()-2);
			//cout<<t<<endl;
			int x=atoi(t.c_str());
			//cout<<x<<endl;
			s=s.substr(0,s.size()-2);
			//cout<<" "<<x<<endl;
			int a=x%10;
			int b=(x-a)/10;
			a+=b;
			if(a/10){
				s+='1';
			}
			a%=10;
			s+=('0'+a);
			//cout<<s<<endl;
			cnt++;
		}
		if(cnt%2){
			cout<<"Fabre wins."<<endl;
		}else
		cout<<"Audrey wins."<<endl;
		//cout<<cnt<<endl;
	}
	return 0;
}