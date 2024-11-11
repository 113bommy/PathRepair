#include<bits/stdc++.h>
using namespace std;
int main(){
 int K;
 cin >> K;
 queue<long long int> p;
 for(int i = 1; i < 10; i++) {
     p.push(i);
 }
 for(int i = 0; i < K - 1; i++) {
     long long s = p.front();
     p.pop();
     for(int j = -1; j <= 1; j++) {
         long long add = (s % 10) + j;
         if(add >= 0 && add <= 9) { p.push(s * 10 + add); }
     }
 }

 cout << p.front() << endl; 
 return 0;
}