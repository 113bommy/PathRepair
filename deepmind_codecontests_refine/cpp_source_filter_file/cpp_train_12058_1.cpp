#include <iostream>
#include <string>
using namespace std;

int main(void){
int n;
string moji [100];
string result =“Yes”;
cin >> n;

cin>>moji[0];

for (int i =1;i<n;i++){
cin >> moji [i];
if(moji[i-1][moji[i-1].length] == moji[i][0]){
result = "No";
}
for(int j=0;j<i;j++){
if(moji[j]==moji[i]){
result = "No";
}
}
}

cout <<  result<< endl;
return 0;
}
