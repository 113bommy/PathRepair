#include<iostream>
using namespace std;
int main()
{
	int x,cnt=0;
	cin>>x;//直接忽略第一个数 
	while(cin>>x)cnt+=x%2;
	cout<<(cnt%2?"NO":"YES")<<endl;
	return 0;
}