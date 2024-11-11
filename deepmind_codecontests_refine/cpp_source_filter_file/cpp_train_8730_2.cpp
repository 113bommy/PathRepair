#include <stdio.h>
using namespace std;
#define rep(i,a,n) for(int i=a; i<n; i++)

int main() {
int n;
while(cin >> n) {
int cnt = 0;
rep(a,0,10) rep(b,0,10) rep(c,0,10) rep(d,0,10) {
if(a + b + c + d == n) cnt++;
}
cout << cnt << endl;
}
return 0;
}