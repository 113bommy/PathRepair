#include<iostream>
using namespace std;
long long p[1<<17],N,Q,A,R,sum,cnt;
int main() {
	cin>>N>>Q;for (int i=0;i<N;i++)cin>>p[i];
	while(Q--){
		sum=0,R=0;cin>>A;cnt=0;
		for(int i=0;i<N;i++){
			while(R<N&&sum+p[R]<=A)sum+=p[R++];
			if(sum>0)sum-=p[i];
			cnt+=R-i;if(R<i+1)R=i+1;
		}
		cout<<cnt<<endl;
	}
}