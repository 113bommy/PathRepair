#include<iostream>
using namespace std;

int n,cnt;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		cnt += (a&1);
	}
	puts((cnt&1)?"NO":"YES");
	return 0;
}
