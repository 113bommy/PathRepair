#include <bits/stdc++.h>
using namespace std;
const int MAX_TEXT = 1e5 + 5;
const int HASH_COUNT = 1;
const unsigned long long HASH_MULT = 1280770307;
const unsigned long long HASH_MOD[] = {14204677, 4254167843U};
int N;
vector<string> words;
vector<unsigned long long> prefix_hash[HASH_COUNT];
vector<unsigned long long> hash_pow[HASH_COUNT];
vector<int> length_sum;
unsigned long long compute_hash(const string &str, int h) {
  unsigned long long value = 0;
  for (char c : str) value = (HASH_MULT * value + c) % HASH_MOD[h];
  return value;
}
unsigned long long segment_hash(int start, int end, int h) {
  const unsigned long long mod = HASH_MOD[h];
  int length = length_sum[end] - length_sum[start];
  unsigned long long value = prefix_hash[h][end] + mod -
                             hash_pow[h][length] * prefix_hash[h][start] % mod;
  return value < mod ? value : value - mod;
}
unsigned long long combined_hash(int start, int end) {
  return (segment_hash(start, end, 0));
}
int segment_length(int start, int end) {
  return length_sum[end] - length_sum[start];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  words.resize(N);
  length_sum.resize(N + 1);
  length_sum[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> words[i];
    words[i] += ' ';
    length_sum[i + 1] = length_sum[i] + words[i].size();
  }
  for (int h = 0; h < HASH_COUNT; h++) {
    const unsigned long long mod = HASH_MOD[h];
    hash_pow[h].resize(MAX_TEXT);
    hash_pow[h][0] = 1;
    for (int i = 1; i < MAX_TEXT; i++)
      hash_pow[h][i] = HASH_MULT * hash_pow[h][i - 1] % mod;
    prefix_hash[h].resize(N + 1);
    prefix_hash[h][0] = 0;
    for (int i = 0; i < N; i++)
      prefix_hash[h][i + 1] =
          (hash_pow[h][words[i].size()] * prefix_hash[h][i] +
           compute_hash(words[i], h)) %
          mod;
  }
  int best_save = 0;
  for (int length = 1; 2 * length <= N; length++) {
    unordered_map<unsigned long long, int> most_recent;
    vector<int> most_segments;
    vector<unsigned long long> hashes;
    for (int i = 0; i + length <= N; i++) {
      if (i >= length) most_recent[hashes[i - length]] = i - length;
      unsigned long long hash_value = combined_hash(i, i + length);
      hashes.push_back(hash_value);
      most_segments.push_back(1);
      if (most_recent.find(hash_value) != most_recent.end())
        most_segments[i] = most_segments[most_recent[hash_value]] + 1;
      if (most_segments[i] >= 2) {
        int save = segment_length(i, i + length) - (length + 1);
        best_save = max(best_save, most_segments[i] * save);
      }
    }
  }
  cout << length_sum[N] - 1 - best_save << '\n';
  return 0;
}
