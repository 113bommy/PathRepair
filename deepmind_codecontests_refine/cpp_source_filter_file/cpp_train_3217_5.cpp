#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){
	while (1){
		int u = 1, d = 6, e = 3, w = 4, n = 5, s = 2;
		int ans = 1;
		int N;
		scanf_s("%d", &N);
		if (N == 0)return 0;
		for (int i = 0; i < N; i++){
			string dir;
			cin >> dir;
			int a;
			if (dir == "North"){
				a = u;
				u = s, s = d, d = n;
				n = a;
			}
			if (dir == "East"){
				a = u, u = w, w = d, d = e, e = a;
			}
			if (dir == "Right"){
				a = s, s = e, e = n, n = w, w = a;
			}
			if (dir == "Left"){
				a = s, s = w, w = n, n = e, e = a;
			}
			if (dir == "West"){
				a = u, u = e, e = d, d = w, w = a;
			}
			if (dir == "South"){
				a = u, u = n, n = d, d = s, s = a;
			}
			ans += u;
		}
		printf("%d\n", ans);
	}
}