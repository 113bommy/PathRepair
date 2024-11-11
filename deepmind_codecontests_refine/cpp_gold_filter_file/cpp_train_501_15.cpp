#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int x, arr[105];
cin >> x;
for(int i=1; i<=x;i++){
cin >> arr[i];
}
sort(arr+1, arr+1+x);
cout << arr[x]-arr[1] << endl;
return 0;
}