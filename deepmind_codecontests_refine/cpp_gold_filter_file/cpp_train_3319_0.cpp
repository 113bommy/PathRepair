#include <iostream>
#define N 1000000 
using  namespace std;

int main(void){
	bool isprime[N+1];
	for(int i=0;i<=N;i++)
		isprime[i]=true;
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=N;i++)
		if(isprime[i])
			for(int j=2*i;j<=N;j+=i)
				isprime[j]=false;
	bool budget[N+1];
	int n,m;
	while(cin >> n>>m,n|m){
		for(int i=0;i<=m;i++)
			budget[i]=false;
		int tmp;
		budget[0]=true;
		for(int i=0;i<n;i++){
			cin >> tmp;
			for(int j=0;j<=m;j++)
				if(budget[j]&&(j+tmp)<=m)
					budget[j+tmp]=true;
		}
		int MAX=0;
		for(int i=m;i>0;i--){
			if(budget[i]&isprime[i]){
				MAX=i;break;
			}
		}
		if(MAX)
			cout << MAX << endl;
		else
			cout << "NA" << endl;
	}
	return 0;
}