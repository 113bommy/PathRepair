#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K;
  cin >>A >>B >>C >>K;
 
 if(K<=A)
  cout<< K;
 
 else if (K<=A+B)
  cout<< A;
 
 else
   cout<<A-(K-A-B);
  
 }