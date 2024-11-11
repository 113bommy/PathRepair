#include<iostream>
using namespace std;

int main(){

	int a, b, N, s, f;
	int ans = 0;
	cin >> a >> b;
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> s >> f;
			//同じ時間を使用しているとき
			if(a == s && b == f) ans =1;
			//時間をすでに使用（被っている）させているとき
			for(int j = s+1; j < f; j++){
				if(a == j || b == j) ans = 1;
			}
			//時間の使い過ぎ
			for(int k = a+1; k < b; k++){
				if( k == s || k == f) ans = 1;
			}
	}

	cout << ans << endl;

	return 0;
}
