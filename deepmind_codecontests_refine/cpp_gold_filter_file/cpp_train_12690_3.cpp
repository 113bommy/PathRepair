#include<iostream>
using namespace std;
int main(int i){
int s[2]={0};
for(;i<6;i++){cin >> s[0];
s[1] += s[0]>39?s[0]:40;
}
cout << s[1]/5 << endl;
return 0;
}