#include<bits/stdc++.h>

using namespace std;

int n, a[105], ans;

int main(){
	scanf("%d%d", &n,, &a[0]);
	for(int i = 1; i < n; i++){
		scanf("%d", &a[i]);
      	if(a[i] == a[i-1]){
          ans++;
          a[i] = 0;
        }
	}
	printf("%d\n", ans);
}