#include<bits/stdc++.h>
using namespace std;
int main(){
int a[10];
for(int i =0; i < 10; i++){
cin >> a[i];
}
sort( a, a + 10, greater<int>());
for(int j = 0; j < 3; j++){
cout << a[j] << endl;
}
return 0;
}