#include <iostream>
using namespace std;
int main(void){
int i, N, ans, max;
cin >> N;
int h[N];
for (i=0;i<N;i++){
cin >> h[i];
}
ans=0;
max=1

for (int j=0; j<N;j++){
if (h[j]>=max)
{
ans++;
max=h[j];
}
}
cout << ans;
}