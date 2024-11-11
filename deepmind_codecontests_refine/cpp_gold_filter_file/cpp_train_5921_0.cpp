#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a; i<n; i++)
using namespace std;
  
int main() {
int w,n; cin >> w >> n;
int a[31];
rep(i,0,w) a[i] = i+1;
  
rep(i,0,n) {
int x,y;
scanf("%d,%d",&x,&y);
swap(a[x-1],a[y-1]);
}
rep(i,0,n) cout << a[i] << endl;
return 0;
}