#include<iostream>
#include<string>
using namespace std;
int main(){
	string row;
	while(1){
		int sum=0;
		cin>>row;
		if(row=='0')break;
		for(int i=0;i<row.size();i++){
			sum+=row[i]-'0';
		}
		cout<<sum<<endl;
	}
	return 0;
}
