#include<bits/stdc++.h>
using namespace std;

int main(){
  long n;
  cin >> n;
  long a[n],sum = 0;
  for(long i = 0;i < n;i++){
    cin >> a[i];
  }
  long kekka = 0;
  for(long i = 0;i < n;i++){
    sum += a[i];
    if(i % 2 == 0 && sum >= 0){
      kekka += sum + 1;
      sum = -1;
    }
    if(i % 2 == 1 && sum <= 0){
      kekka += -sum + 1;
      sum = 1;
    }
  }
  long result = 0;
  sum = 0;
  for(long i = 0;i < n;i++){
    sum += a[i];
    if(i % 2 == 0 && sum <= 0){
      result += -sum + 1;
      sum = 1;
    }
    if(i % 2 == 1 && sum >= 0){
      result += sum + 1;
      sum = -1;
    }
  }
  cout << min(kekka,result) << endl;
}