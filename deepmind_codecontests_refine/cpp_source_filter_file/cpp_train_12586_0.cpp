//#define kotani int
#include<iostream>
#include<algorithm>
using namespace std;
int search(int rank);
int time[100000];
int nagase_time[100000];
int n,k;
int ans,www;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>time[i];
	}
	/*k-=n;
	ans=n;
	if(k<0){
		int num=-1;
		for(int i=0;i<k;i++){
			num=+search(num);
			ans+=num;
		}
	}*/
	for(int i=1;i<n;i++){
		nagase_time[i-1]=time[i]-time[i-1]-1;
		//cout<<"ww"<<nagase_time[i-1]<<endl;
	}
	sort(nagase_time,nagase_time+(n-1));
	/*for(int i=0;i<n-1;i++){
		cout<<nagase_time[i]<<endl;
	}*/
	www=n-k;
	ans=0;
	for(int i=0;i<www;i++){
		ans+=nagase_time[i];
	}
	cout<<ans+n<<endl;
}
int search(int rank){
	int min=-1,sub;
	for(int i=0;i<n-1;i++){
		if(time[i+1]-time[i]<min||min==-1){
			sub=min;
			min=time[i+1]-time[i];
		}
		if(min<rank){
			min=sub;
		}
	}
	return min;
}
