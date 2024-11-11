include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
int main(){
	int N, C, K, T[100000];
	cin >> N >> C >> K;
	for(int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	int ans = 0;
	for(int i = 0; i < N; i++){
		int s = T[i];
		int cnt = 1;
		while(cnt < C && T[i + 1] - s <= K){
			cnt++;
			i++;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}