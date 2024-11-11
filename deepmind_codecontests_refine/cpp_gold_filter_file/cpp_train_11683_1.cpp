#include <bits/stdc++.h>
using namespace std;
int N, K;
char input[200000];
vector<int> places;
string solution;
void print_next_character() {
  for (char c = 'a'; c <= 'z'; c++) {
    long long skipped = 0;
    vector<int> new_places;
    int count = 0;
    for (int i = 0; i < (int)places.size(); i++)
      if (input[places[i]] == c) {
        if (places[i] + 1 != N) new_places.push_back(places[i] + 1);
        skipped += N - places[i];
        count++;
      }
    if (skipped >= K) {
      K -= count;
      putchar(c);
      places = new_places;
      return;
    } else
      K -= skipped;
  }
}
int main() {
  gets(input);
  N = strlen(input);
  scanf("%d", &K);
  if (K > (long long)N * (N + 1) / 2) {
    puts("No such line.");
    return 0;
  }
  for (int i = 0; i < N; i++) places.push_back(i);
  while (K > 0) print_next_character();
  printf("\n");
  return 0;
}
