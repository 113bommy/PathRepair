#include <cstdio>
#include <algorithm>
using namespace std;

int h, w;
char s[13][13];
char ns[13][13];

int p[13];
bool used[13];

bool finished;

void check(){
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			ns[i][j] = s[i][p[j]];


	int cnt=0;
	int chk = 0;
	for(int i=1; i<=h; i++){
		if(chk & (1<<i)) continue;
		bool found=false;
		for(int j=i+1; j<=h; j++){
			if(chk & (1<<j)) continue;
			bool flag=true;
			for(int k=1, l=w; k<=w; k++, l--)
				if(ns[i][k] != ns[j][l]){
					flag=false;
					break;
				}
			if(flag){
				found=true;
				chk |= (1<<i);
				chk |= (1<<j);
				break;
			}
		}
		if(!found) cnt++;
		if((h%2==0 && cnt>0) || (h%2==1 && cnt>1)) return;
	}
	finished = true;
}

void backtrack(int now, int val, int cnt){
	for(int i=val+1; i<=w; i++){
		if(used[i]) continue;
		used[i]=true;
		p[now]=i;

		if(cnt == w){ /// end condition
			check();
		}
		else if(cnt&1) backtrack(w+1-now, i, cnt+1);
		else backtrack(w+2-now, 0, cnt+1);

		used[i]=false;

		if(finished) return;
	}
	return;
}

int main(){
	scanf("%d %d", &h, &w);
	for(int i=1; i<=h; i++){
		scanf("\n");
		for(int j=1; j<=w; j++)
			scanf("%c", &s[i][j]);
	}
	backtrack(1, 0, 1);
	puts(finished?"YES":"NO");
	return 0;
}
