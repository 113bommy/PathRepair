#include<iostream>
#include<algorithm>
#include<map>
using namespace std;



int main(){

 map<int,bool>memo; 
 int n;
 cin>>n;
 int cnt=0;

 for(int i=0;i<n;i++){
	int p[3];
	cin>>p[0]>>p[1]>>p[2];

	sort(p,p+3);

	int k=((p[0]-1)*1000+(p[1]-1))*1000+(p[2]-1);

	if(memo.find(k)!=memo.end()){
		cnt++;
	}else{
		memo[k]=true;
	}
 }
cout<<cnt<<endl;

return 0;
}