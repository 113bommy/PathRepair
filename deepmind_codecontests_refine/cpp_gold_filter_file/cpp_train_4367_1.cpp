#include <iostream>
#include <string>
using namespace std;

int main(){
	while(true){
		string s1;
		cin>>s1;
		if(s1=="."){
			break;
		}
		string s2;
		cin>>s2;
		if(s1==s2){
			cout<<"IDENTICAL"<<endl;
			continue;
		}
		string t1=s1;
		string t2=s2;
		while(true){
			size_t d1b=t1.find('\"');
			if(d1b==string::npos){
				break;
			}
			t1.replace(d1b,1,"@");
			size_t d1e=t1.find('\"');
			t1.replace(d1e,1,"@");

			size_t d2b=t2.find('\"');
			if(d2b==string::npos){
				break;
			}
			t2.replace(d2b,1,"@");
			size_t d2e=t2.find('\"');
			t2.replace(d2e,1,"@");

			string u1=s1;
			u1.replace(d1b+1,d1e-d1b-1,"");
			string u2=s2;
			u2.replace(d2b+1,d2e-d2b-1,"");

			if(u1==u2){
				t1=u1;
				t2=u2;
				break;
			}
		}
		if(t1==t2){
			cout<<"CLOSE"<<endl;
		}
		else{
			cout<<"DIFFERENT"<<endl;
		}
	}
	return 0;
}