#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int result=0;
  for(int i=1;i<N+1;i++){
    int count=i%10+i/10%10+i/100%10+i/1000%10+i/10000;
    if(A<=count&&count<=B) result+=i
  }
  cout << result << endl;
}
