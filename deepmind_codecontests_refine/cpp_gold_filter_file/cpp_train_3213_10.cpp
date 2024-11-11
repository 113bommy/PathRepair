#include<iostream>
using namespace std;

int main(void){
  long long A, B, N;
  cin >> A >> B >> N;
  cout << (B + N) / N - (A + N - 1) / N << endl;
  return 0;
}
