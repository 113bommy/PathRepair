#include <iostream>

using namespace std;
#define max 1260-540

bool times[10000][max+1];

int main(void){
	int N,M,r,q;
	while(cin >> N  >> M, N|M){
		for(int i=0;i<M;i++)
			for(int j=0;j<=max;j++)
				times[i][j]=false;

		cin >> r;
		int start[1001];
		for(int i=0;i<r;i++){
			int t,n,m,s;
			cin >> t >> n >> m >> s;
			if(s)
				start[n]=t-520;
			else{
				for(int k=start[n];k<t-520;k++)
					times[m][k]=true;
			}
		}
		cin >> q;
		for(int i=0;i<q;i++){
			int ts,te,m;
			cin >> ts >> te >> m;
			int num=0;
			for(int i=ts-520;i<te-520;i++){
				if(times[m][i])
					num++;
			}
			cout << num << endl;
		}
	}

	return 0;
}