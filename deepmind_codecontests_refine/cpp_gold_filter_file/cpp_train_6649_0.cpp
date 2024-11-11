#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
	string str;

	int data[2][1001][40];
	for(int i=0;i<=1000;i++){
		for(int j=0;j<40;j++){
			for(int k=0;k<2;k++){
				data[k][i][j]=0;
			}
		}
	}

	while(getline(cin,str)){
		if(str.empty())break;
		for(int i=0;i<str.size();i++){
			int spaceN = str.find(',',0);
			int person=atoi(str.substr(0,spaceN).c_str());
			int date  =atoi(str.substr(spaceN+1,str.size()-1).c_str());
			data[0][person][date]=1;
		//	cout<<"p="<<person<<" date="<<date<<endl;
		}
	}

	while(cin>>str){
	if(str.at(0)=='0')break;
		for(int i=0;i<str.size();i++){
			int spaceN = str.find(',',0);
			int person=atoi(str.substr(0,spaceN).c_str());
			int date  =atoi(str.substr(spaceN+1,str.size()-1).c_str());
			data[1][person][date]=1;
		}
	}
	int cnt=0;
	int flag=0;

	for(int j=0;j<=1000;j++){
		cnt=0;
		flag=0;
		for(int i=1;i>=0;i--){
			for(int k=0;k<40;k++){
				if(i==1){
					if(data[i][j][k]==1){
						cnt++;
						flag=1;
					}
				}
				else{
					if(data[i][j][k]==1&&flag>=1){
						cnt++;
						flag=2;
					}
				}
			}
		}
		if(flag==2){
			cout<<j<<" "<<cnt<<endl;
		}
	}
				
	return 0;

}