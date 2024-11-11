#include <iostream>
#include <string>
#include <utility>
using namespace std;
void rotate(int& a,int& b,int& c,int& d){
	swap(a,b);
	swap(a,d);
	swap(c,d);
}
int main()
{
	while(true){
		int n,sum=1,num[6]={1,2,3,4,5,6};
		string s;
		cin>>n;
		if(!n)break;
		while(n--){
			cin>>s;
			if(s=="North")rotate(num[5],num[1],num[0],num[4]);
			else if(s=="South")rotate(num[4],num[0],num[1],num[5]);
			else if(s=="West")rotate(num[5],num[2],num[0],num[3]);
			else if(s=="East")rotate(num[3],num[0],num[2],num[5]);
			else if(s=="Right")rotate(num[1],num[3],num[4],num[2]);
			else if(s=="Left")rotate(num[2],num[4],num[3],num[1]);
			sum+=num[0];
		}
		cout<<sum<<endl;
	}
    return 0;
}