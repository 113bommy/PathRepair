#include<iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
while(1){
int n = 0;
cin >> n;
if(n == 0){break;}
int sum = 1;
int a[7];
for(int i = 0;i <= 6;i++){
a[i] = i + 1;
}
for (int i = 1;i <= n;i++){
string c;string N = "North";string E = "East";string S  = "South";string W = "West";
string R = "Right";string L = "Left";
cin >> c;
if(c == N){
a[6] = a[0];a[0] = a[1];a[1] = a[5];a[5] = a[4];a[4] = a[6];
}
if(c == S){
a[6] = a[0];a[0] = a[4];a[4] = a[5];a[5] = a[1];a[1] = a[6];
}
if(c == E){
a[6] = a[0];a[0] = a[3];a[3] = a[5];a[5] = a[2];a[2] = a[6];
}
if(c == W){
a[6] = a[0];a[0] = a[2];a[2] = a[5];a[5] = a[3];a[3] = a[6];
}
if(c == R){
a[6] = a[1];a[1] = a[2];a[2] = a[4];a[4] = a[3];a[3] = a[6];
}
if(c == L{
a[6] = a[1];a[1] = a[3];a[3] = a[4];a[4] =a[2];a[2] = a[6];
}
sum = sum + a[0];
}
cout << sum << endl;
}
    return 0;
}