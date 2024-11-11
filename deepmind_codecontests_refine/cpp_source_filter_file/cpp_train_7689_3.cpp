#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	while(cin>>str){
		int num[10];
		for(int i=0;i<10;i++){
			num[i]=str[i]-48;
		}
		for(int j=9;j>=0;j--){
			for(int k=0;k<j;k++){
				num[k] += num[k+1];
			}
		}
		cout<<num[k]%10<<endl;	
	}
	return 0;
}