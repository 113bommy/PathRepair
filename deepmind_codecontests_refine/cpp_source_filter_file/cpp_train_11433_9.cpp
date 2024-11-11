#include <bits/stdc++.h>
using namespace std;
int main(){
string N;
cin >> N;
if(N.size()==2){
cout << N << endl;
}
else if (N.size() ==3){
for(int i=0;i<3;i++){
cout <<N[2-i];
}
}