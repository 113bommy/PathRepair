#include <bits/stdc++.h>
using namespace std;
const int MAX = 256;
long long func[MAX];
int main() {
  string input;
  cin >> input;
  for (int i = 0; i < MAX; i++) func[i] = 0;
  int n = input.length();
  long long result = 0;
  for (int i = n - 1; i >= 0; i--) {
    func[input[i]]++;
  }
  for (int i = 0; i < MAX; i++) result += func[i] * func[i];
  cout << result;
}
