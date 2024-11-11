#include <iostream>
using namespace std;

int main() {
  int N, a, b, res;
  signed int invite[100000] = {0};

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    invite[a-1]++;
    invite[b]--;
  }

  signed int sum = 0;
  for(int i = 0; i < N+1; i++) {
    sum += invite[i];
    if(i <= sum)
      res = i;
  }
  cout << res << endl;
}

