#include <iostream>
using namespace std;

int main(){
int K,S;

cin>>K>>S;
int res=0;
for(int x=0; x <= K; ++x){
for(int y=0; y <= K; ++y){ 
int z = S-x-y;
if (total==K) ++res;
} 
}
cout << res <<endl;
}