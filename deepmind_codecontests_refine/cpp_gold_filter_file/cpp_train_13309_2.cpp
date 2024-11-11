#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<long> a(n);
  for (int i=0; i<n; i++) cin >> a[i];
  
  long odd = 0, even = 0, sum = 0;
  
  for (int i=0; i<n; i++){
    sum += a[i];
    if(i%2==0&&sum<=0){
      odd += abs(sum)+1;
      sum = +1;
    }
    else if(i%2==1&&sum>=0){
      odd += abs(sum)+1;
      sum = -1;
    }
  }
  
  sum = 0;
  for (int i=0; i<n; i++){
    sum += a[i];
    if (i%2==1&&sum<=0){
      even += abs(sum)+1;
      sum = +1;
    }
    else if(i%2==0&&sum>=0){
      even+=abs(sum)+1;
      sum=-1;
    }
  }
  
  cout << min(odd,even) << endl;
  
}