#include<iostream>
#include<string>
using namespace std;
string a[1000];
int time[1000][2];
int main(){
	int n,m,z;
	while(true){
	cin>>n>>m;
	if(n==0&&m==0)break;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>z>>time[i][1];
		time[i][0]=time[i][1]-z;
	}
	for(int u=0;u<m;u++){
		string ans="Unknown";
		int cnt=-1;
		cin>>z;
		for(int i=0;i<n;i++)if(time[i][0]<z&&time[i][1]>=z){ans=a[i],cnt=z-time[i][0];}
		cout<<ans;
		if(cnt>0)cout<<" "<<cnt;
		cout<<endl;
	}
	}
	return 0;
}