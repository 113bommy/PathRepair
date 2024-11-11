#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(void)
{
	int  n;
	
	while(cin >> n, n){
		int a = 0;
		long longint ans = 0;
		int time[10000];
		for(int i = 0; i < n; i++){
			cin >> time[i];
		}
		
		sort(time, time + n);
		int temp = n;
		for(int j = 0; j < n-1; j++){
			a = 0;
			for(int ii = 0; ii < temp-1; ii++){
				a += time[ii];
			}
			ans += a;
			temp--;
		}
		cout << ans << endl;
	}
	return 0;
}