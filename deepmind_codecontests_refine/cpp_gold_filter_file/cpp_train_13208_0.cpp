#include<bits/stdc++.h>
using namespace std;

/*int stoi(string a){
	int ret;
	stringstream ss;
	ss<<a;
	ss>>ret;
	return ret;
	}*/

int main(){
	string s;
	while(getline(cin,s)&&s!="0"){
		s.push_back(' ');
		int one=0;
		int sum=0;
		
		string a;
		for(int i=0;i<s.size();i++){
			if(s[i]==' '){
				int b=stoi(a);
				if(b==1)one++;
				else if(b>10)sum+=10;
				else sum+=b;
				a.clear();
				}
			else a.push_back(s[i]);
			}
			sum+=one;
			for(int i=0;i<one;i++){
				if(sum<12)sum+=10;
				}	
				
			if(sum>21)sum=0;	
			cout<<sum<<endl;	
		}
	return 0;
	}