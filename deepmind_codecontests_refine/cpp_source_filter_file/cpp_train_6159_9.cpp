#include <bits/stdc++.h>
using namespace std;
enum characterSets { lowerCase, upperCase, bothCharSets };
const constexpr char *extraCharacters = "";
const characterSets relevantCharacterSets = bothCharSets;
constexpr int constStrLen(const char *str, int i = 0) {
  return str[i] == '\0' ? 0 : constStrLen(str, i + 1) + 1;
}
constexpr int getNumChars(characterSets charSets, const char *extraCharacters) {
  return constStrLen(extraCharacters) +
         (charSets == lowerCase   ? 'z' - 'a' + 1
          : charSets == upperCase ? 'Z' - 'A' + 1
                                  : int('z' - 'a') + 1 + int('Z' - 'A') + 1);
}
const int numChars = getNumChars(relevantCharacterSets, extraCharacters);
vector<pair<char, char>> characterRanges;
bool characterRangesInitialized;
void initializeCharacterRange() {
  if (characterRangesInitialized) return;
  characterRangesInitialized = true;
  characterRanges = vector<pair<char, char>>();
  if (relevantCharacterSets == lowerCase ||
      relevantCharacterSets == bothCharSets)
    characterRanges.push_back({'a', 'z'});
  if (relevantCharacterSets == upperCase ||
      relevantCharacterSets == bothCharSets)
    characterRanges.push_back({'A', 'Z'});
  for (int i = 0; extraCharacters[i]; i++)
    characterRanges.push_back({extraCharacters[i], extraCharacters[i]});
}
int convertCharToIndex(char c) {
  int ret = 0;
  for (auto range : characterRanges)
    if (c >= range.first && c <= range.second)
      return ret + int(c - range.first);
    else
      ret += int(range.second - range.first) + 1;
}
class AhoCorasick {
 private:
  struct Node {
    int next[numChars];
    int fallbackIndex;
    int longestWordEndingHere = -1;
    int firstWordEndingHere = -1;
    Node() { memset(next, -1, sizeof(next)); }
    int &getNextIndex(char c) { return next[convertCharToIndex(c)]; };
    int &getNextIndex(int i) { return next[i]; };
  };
  vector<Node> nodes;
  void insertToTrie(string &word, int wordIndex) {
    int curIndex = 0;
    for (char c : word) {
      if (nodes[curIndex].getNextIndex(c) == -1) {
        nodes[curIndex].getNextIndex(c) = int(nodes.size());
        nodes.emplace_back();
      }
      curIndex = nodes[curIndex].getNextIndex(c);
    }
    if (nodes[curIndex].longestWordEndingHere == -1)
      nodes[curIndex].firstWordEndingHere = wordIndex;
    nextMatchingWord.push_back(nodes[curIndex].longestWordEndingHere);
    nodes[curIndex].longestWordEndingHere = wordIndex;
  }
  int curState = 0;
  vector<int> nextMatchingWord;
  vector<string> dictionary;

 public:
  AhoCorasick(vector<string> &dictionary) : dictionary(dictionary) {
    initializeCharacterRange();
    nodes.emplace_back();
    nextMatchingWord.reserve(dictionary.size());
    for (int i = 0; i < (int)dictionary.size(); i++)
      insertToTrie(dictionary[i], i);
    queue<int> q;
    nodes[0].fallbackIndex = -1;
    for (q.push(0); !q.empty(); q.pop()) {
      Node &curNode = nodes[q.front()];
      for (int c = 0; c < numChars; c++) {
        int &nextIndex = curNode.getNextIndex(c);
        int fallbackIndex = curNode.fallbackIndex == -1
                                ? 0
                                : nodes[curNode.fallbackIndex].getNextIndex(c);
        if (nextIndex == -1)
          nextIndex = fallbackIndex;
        else {
          nodes[nextIndex].fallbackIndex = fallbackIndex;
          if (nodes[nextIndex].longestWordEndingHere == -1)
            nodes[nextIndex].longestWordEndingHere =
                nodes[fallbackIndex].longestWordEndingHere;
          else
            nextMatchingWord[nodes[nextIndex].firstWordEndingHere] =
                nodes[fallbackIndex].longestWordEndingHere;
          q.push(nextIndex);
        }
      }
    }
  }
  void transitionState(char c) { curState = nodes[curState].getNextIndex(c); }
  void resetState() { curState = 0; }
  int getCurState() { return curState; }
  void setCurState(int newState) { curState = newState; }
  int getMaxState() { return int(nodes.size()) - 1; }
  int getLongestWordHere() { return nodes[curState].longestWordEndingHere; }
  vector<int> getAllWordsEndingHere() {
    vector<int> ret;
    int curWord = getLongestWordHere();
    while (curWord != -1) {
      ret.push_back(curWord);
      curWord = nextMatchingWord[curWord];
    }
    return ret;
  }
  vector<int> findLongestWords(string &s) {
    vector<int> ret;
    ret.reserve(int(s.size()));
    int curIndex = 0;
    for (auto c : s) {
      curIndex = nodes[curIndex].getNextIndex(c);
      ret.push_back(nodes[curIndex].longestWordEndingHere);
    }
    return ret;
  }
  vector<vector<int>> findAllWords(string &s) {
    vector<vector<int>> ret(s.size(), vector<int>());
    vector<int> seed = findLongestWords(s);
    for (int i = 0; i < int(seed.size()); i++) {
      int curIndex = seed[i];
      while (curIndex != -1) {
        ret[i - int(dictionary[curIndex].size()) + 1].push_back(curIndex);
        curIndex = nextMatchingWord[curIndex];
      }
    }
    return ret;
  }
};
const int INTINF = (int)0x3f3f3f3f;
const long long int LONGINTINF = (long long int)0x3f3f3f3f3f3f3f3f;
const double DOUBLEINF = 1.38241720848787153030907987683E306;
const int INTNEG = (int)0x80808080;
const long int LONGINTNEG = (long long int)0x8080808080808080;
const double DOUBLENEG = -5.31401037251780764728375028654E303;
int dp[1050][110];
int nextS[55][26], nextT[55][26];
void buildKMPTable(string &w, int nextptr[][26]) {
  int m = w.size();
  vector<int> T(m + 1);
  T[0] = -1;
  T[1] = 0;
  int pos = 2;
  int cnt = 0;
  while (pos <= m) {
    if (w[pos - 1] == w[cnt]) {
      T[pos] = cnt + 1;
      pos++;
      cnt++;
    } else if (cnt) {
      cnt = T[cnt];
    } else {
      T[pos] = 0;
      pos++;
    }
  }
  for (int i = (0); i < (m + 1); i++)
    for (int c = ('a'); c < ('z' + 1); c++) {
      int d = i;
      if (d == m) d = T[d];
      while (d > -1 && w[d] != c) d = T[d];
      nextptr[i][c] = d + 1;
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.setstate(ios_base::failbit);
  string code, s, t;
  cin >> code >> s >> t;
  memset((dp), 0x80, sizeof(dp));
  dp[0][0] = 0;
  vector<string> dict = {s, t};
  AhoCorasick AC(dict);
  int ret = INTNEG;
  for (int i = (0); i < (int(code.size()) + 1); i++)
    for (int j = (0); j < (AC.getMaxState()); j++)
      if (dp[i][j] != INTNEG)
        for (int c = ('a'); c < ('z' + 1); c++) {
          if (i == int(code.size())) {
            ret = max((ret), (dp[i][j]));
            break;
          }
          if (code[i] != '*' && code[i] != c) continue;
          AC.setCurState(j);
          AC.transitionState(c);
          auto words = AC.getAllWordsEndingHere();
          int nextVal = dp[i][j];
          if (words.size() == 1) nextVal += words[0] == 0 ? 1 : -1;
          dp[i + 1][AC.getCurState()] =
              max((dp[i + 1][AC.getCurState()]), (nextVal));
        }
  cout << ret << '\n';
}
