#include <cstdio>

int n, tn, hn, turn, card;
bool t[201], h[201];

int main(){
	while(scanf("%d", &n)){
		if(n == 0) break;
		tn = n; hn = n;
		turn = 1; card = 0;
		for(int i = 1; i <= 200; i++){
			t[i] = false;
			h[i] = false;
		}
		for(int i = 1; i <= n; i++){
			int tmp; scanf("%d", &tmp);
			t[tmp] = true;
		}
		for(int i = 1; i <= 2*n; i++) if(!t[i]) h[i] = true;
		while(true){
			bool ok = true;
			if(tn == 0 || hn == 0){
				printf("%d\n%d\n", hn, tn);
				break;
			}
			if(turn == 1){
				for(int i = card+1; i <= 2*n; i++){
					if(t[i]){
						t[i] = false;
						card = i;
						turn = 2;
						tn--;
						ok = false;
						break;
					}
				}
				if(ok){
					turn = 2;
					card = 0;
				}
			} else{
				for(int i = card+1; i <= 2*n; i++){
					if(h[i]){
						h[i] = false;
						card = i;
						turn = 1;
						hn--;
						ok = false;
						break;
					}
				}
				if(ok){
					turn = 1;
					card = 0;
				}
			}
		}
	}
}