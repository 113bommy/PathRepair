#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int h, w, n;
int sr, sc;
char str1[200005];
char str2[200005];

bool must_fall(int m, int sp, char dec, char inc){
	// one-dimensional version
	// try < 1
	int cp = sp;
	for(int i = 1; i <= n; i++){
		if(str1[i] == dec){
			cp--;
			if(cp == 0){
				return true;
			}
		}
		if(str2[i] == inc && cp < m){
			cp++;
		}
	}
	// try > m
	int cp = sp;
	for(int i = 1; i <= n; i++){
		if(str1[i] == inc){
			cp++;
			if(cp > m){
				return true;
			}
		}
		if(str2[i] == dec && cp > 1){
			cp--;
		}
	}
	return false;
}

int main(){
	scanf("%d %d %d", &h, &w, &n);
	scanf("%d %d", &sr, &sc);
	scanf(" %s", str1 + 1);
	scanf(" %s", str2 + 1);
	if(must_fall(h, sr, 'U', 'D')){
		printf("NO\n");
	}else if(must_fall(w, sc, 'L', 'R')){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
	return 0;
}