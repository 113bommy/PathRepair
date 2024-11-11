#include <bits/stdc++.h>
using namespace std;
class Trie {
  class TrieNode {
   public:
    TrieNode* children[2];
    pair<bool, int> isEndOfWord;
    TrieNode() {
      children[0] = NULL;
      children[1] = NULL;
      isEndOfWord.first = false;
      isEndOfWord.second = 0;
    }
    int number_of_children() {
      int total = 0;
      if (children[0]) total++;
      if (children[1]) total++;
      return total;
    }
  };
  TrieNode* root;

 public:
  Trie() { root = new TrieNode; }
  void insert(string key) {
    TrieNode* temp = root;
    for (int i = 0; i < key.length(); i++) {
      int index = key[i] - '0';
      if (!temp->children[index]) temp->children[index] = new TrieNode;
      temp = temp->children[index];
    }
    temp->isEndOfWord.first = true;
    temp->isEndOfWord.second++;
  }
  string best_match(string key) {
    string bestMatch;
    TrieNode* temp = root;
    for (int i = 0; i < key.length(); i++) {
      int index = key[i] - '0';
      if (!temp->children[index]) (bool)index ? index = 0 : index = 1;
      bestMatch += to_string(index);
      temp = temp->children[index];
    }
    return bestMatch;
  }
  void remove(string key) {
    TrieNode* lastNode = root;
    TrieNode* splitNode = root;
    int splitIndex = 0;
    for (int i = 0; i < key.length(); i++) {
      lastNode = lastNode->children[key[i] - '0'];
      if (lastNode->number_of_children() == 2) {
        splitNode = lastNode;
        splitIndex = key[i + 1] - '0';
      }
    }
    if (lastNode->number_of_children() == 0) {
      lastNode->isEndOfWord.second--;
      if (lastNode->isEndOfWord.second == 0)
        splitNode->children[splitIndex] = NULL;
    } else {
      lastNode->isEndOfWord.second--;
      if (lastNode->isEndOfWord.second == 0)
        lastNode->isEndOfWord.first = false;
    }
  }
};
string DecToBin(int number) {
  if (number == 0) return "0";
  if (number == 1) return "1";
  if (number % 2 == 0)
    return DecToBin(number / 2) + "0";
  else
    return DecToBin(number / 2) + "1";
}
long long BinToDec(string number) {
  int result = 0, pow = 1;
  for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
    result += (number[i] - '0') * pow;
  return result;
}
int main() {
  int num_bits = 31;
  int N;
  cin >> N;
  vector<string> A;
  for (int i = 0; i < N; i++) {
    int number;
    cin >> number;
    string binary = DecToBin(number);
    string padded_binary = string(num_bits - binary.length(), '0') + binary;
    A.push_back(padded_binary);
  }
  Trie P;
  for (int i = 0; i < N; i++) {
    int number;
    cin >> number;
    string binary = DecToBin(number);
    string padded_binary = string(num_bits - binary.length(), '0') + binary;
    P.insert(padded_binary);
  }
  for (int i = 0; i < N; i++) {
    string bestMatch = P.best_match(A[i]);
    P.remove(bestMatch);
    cout << (BinToDec(A[i]) ^ BinToDec(bestMatch)) << " ";
  }
  return 0;
}
