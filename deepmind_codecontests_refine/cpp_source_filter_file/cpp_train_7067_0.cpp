#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;

  int p[5000];
  for(int i=0; i<n; i++){
    cin >> p[i];
  }

  int min_sum = 200000;

  for(int I=0; I<=p[0]; I++){
    int q[5000];
    for(int i=0; i<n; i++){
      q[i]=p[i];
    }

    int sum = I;
    q[0] -= I;

    for(int i=0; i<=n-2; i++){
      if(q[i]<=0){
        continue;
      }

      sum += q[i]*2;
      q[i+1] -= q[i];
    }

    if(q[n-i]>0){
      sum += q[n-1];
    }
    min_sum = min(min_sum, sum);
  }
  cout << min_sum << endl;
  return 0;
}
