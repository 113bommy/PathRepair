#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
long long int INF = 1e18;
/*
int main(){
	while(true){
		int n, d;
		cin >> n >> d;
		
		if(n == 0){
			break;
		}
		
		vector<long long int> v[110];
		long long int S[110] = {};
		
		for(int i = 0; i < n; i++){
			int m;
			cin >> m;
			v[i].push_back(INF);
			for(int j = 0; j < m; j++){
				int num;
				cin >> num;
				v[i].push_back(num);
				S[i] += num;
			}
		}
		
		while(true){
			vector<P> vs;
			for(int i = 0; i < n; i++){
				vs.push_back(make_pair(S[i], i));
			}
			sort(vs.begin(), vs.end());
			bool flag = true;
			for(int i = 0; i < n; i++){
				int index = n - 1;
				if(i == vs[n - 1].second){
					index--;
				}
				if(vs[index].first - d <= S[i] - v[i][v[i].size() - 1]){
					S[i] -= v[i][v[i].size() - 1];
					v[i].pop_back();
					flag = false;
				}
			}
			if(flag){
				break;
			}
		}
		
		int SS = 0;
		for(int i = 0; i < n; i++){
			SS += v[i].size();
		}
		
		if(SS == n){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
*/
char S[80001];
int A, B[11];
 
int char_to_int(char c){
    return (int)c - (int)'0';
}
 
int main(){
    int N, i, j, ans;
    while(1){
        scanf("%s", S);
        for(N = 0; S[N] != '\0'; N++){}
        if(N == 1 && S[0] == '0'){
            return 0;
        }
        for(j = 0; j < 11; j++){
            B[j] = 0;
        }
        B[0] = 1;
        A = 0;
        ans = 0;
        for(i = N - 1; i >= 0; i--){
            if(i % 2 == 0){
                A = (A + char_to_int(S[i])) % 11;
            }
            else{
                A = (A - char_to_int(S[i]) + 11) % 11;
            }
            if(S[i] != '0'){
                ans += B[A];
            }
            B[A]++;
        }
        printf("%d\n", ans);
    }
}
