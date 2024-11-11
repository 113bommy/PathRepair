#include <bits/stdc++.h>
using namespace std;
int main(){
str N;
cin >> N;
if(N.size()==2){
cout << N << endl;
}
else if (N.size() ==3){
for(i=0;i<3;i++){
cout <<N[2-i];
}
}
