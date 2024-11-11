#include<bits/stdc++.h>
using namespace std;

int main(){
   int a, b;
   cin >> a;
   int arr[a];
   for(int i=0; i<a; i++){
      cin >> b;
      arr[b-1]=i+1;
   }
  for(int i=0; i<a; i++){
     cout << arr[i] << ' ';
  }
}
