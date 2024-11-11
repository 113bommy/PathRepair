#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	int p[100];
	for(int i=0;i<N;i++){
		cin>>p[i];
	}
	
	sort(p,p+N);
	
	int score=0;
	for(int i=1; i<=N;i++){
		if(((p+N)-lower_bound(p,p+N,i))>=i){
			score=i;
		}
		else{
			break;
		}
	}
	
	cout<<score<<endl;
	
	return 0;
}