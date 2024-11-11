
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;
  const char tap[] = {'L', 'R'};
  int i = 0;
  for (; i < S.length(); ++i)
    if (tap[i%2] == S[i])
      break;
  cout << (S.length == i ? "Yes" : "No");
  return 0;
}
