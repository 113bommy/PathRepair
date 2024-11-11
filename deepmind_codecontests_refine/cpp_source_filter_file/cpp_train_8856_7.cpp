#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string W,T;
	int cnt=0,i=0;
	cin>>W;
	while(1){
		i++
		cin>>T;
		if(T=="END_OF_TEXT") break;
		transform(T.begin(),T.end(),T.begin(),tolower);
		if(W==T) cnt++;
	}

	cout<<cnt<<endl;
	return 0;
}
