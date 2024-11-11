#include <iostream>
#include <vector>
using namespace std;
int main(){
    int i,N,ans;
cin >> N;
vector <int> p(N);
for(i=0;i<N;i++){
    cin >> p[i];
}
ans = 0;
for(i=0;i<N-1;i++){
if(p[i]==i+1){
    p[i+1]=p[i];
    ans +=1
}
}
if(p[N-1]==N){
    ans += 1;
}
cout << ans << endl;}