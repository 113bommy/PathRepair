#include <bits/stdc++.h>
using namespace std;
const int QUESTION = 1, EXCLAMATION = 2;
string puzzle;
vector<string> queries;
int query(string s, int param) {
  if (param == QUESTION) {
    queries.push_back(s);
    cout << "? " << s << endl;
    int k;
    cin >> k;
    if (k == -1) {
      exit(0);
    }
    int first_pos = -1;
    for (int i = 0; i < k; i++) {
      int pos;
      cin >> pos;
      pos--;
      puzzle.replace(pos, s.size(), s);
      if (first_pos == -1) first_pos = pos;
    }
    return first_pos;
  }
  if (param == EXCLAMATION) {
    string test;
    if (s.find("?") != string::npos)
      for (auto s : queries) test += s + "/";
    cout << "! " << test + s << endl;
    int k;
    cin >> k;
    if (k == 0) {
      exit(0);
    }
    queries.clear();
    return 1;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    puzzle.assign(n, '?');
    int pos1, pos2;
    pos1 = query("CO", QUESTION);
    pos2 = query("CH", QUESTION);
    if (pos1 != -1 || pos2 != -1) {
      int pos = (pos1 == -1 ? pos2 : pos1);
      int l = pos, r = pos + 2;
      while (l != 0 || r <= n) {
        bool from_right = true;
        while (r <= n && puzzle[r] != '?') r++;
        if (r > n) {
          while (l > 0 && puzzle[l - 1] != '?') l--;
          from_right = false;
        }
        if (l == 0 && r > n) break;
        int next_l = l, next_r = r, q_pos;
        if (from_right) {
          next_r += 1;
          q_pos = r;
        } else {
          next_l -= 1;
          q_pos = l - 1;
        }
        string s_for_query = puzzle.substr(next_l, next_r - next_l);
        int question_pos = s_for_query.find("?");
        s_for_query[question_pos] = 'H';
        query(s_for_query, QUESTION);
        if (puzzle[q_pos] == '?') {
          s_for_query[question_pos] = 'O';
          query(s_for_query, QUESTION);
          if (puzzle[q_pos] == '?') puzzle[q_pos] = 'C';
        }
        next_l = l;
        next_r = r;
      }
      query(puzzle, EXCLAMATION);
    } else {
      pos1 = query("OH", QUESTION);
      pos2 = query("HO", QUESTION);
      int last_OH = -1;
      if (pos1 != -1 || pos2 != -1) {
        int sz_q = 0;
        for (int i = 0; i < puzzle.size(); i++) {
          if (puzzle[i] == '?') sz_q++;
          if (puzzle[i] == 'H') {
            for (int j = i - sz_q; j < i; j++) puzzle[j] = 'H';
            sz_q = 0;
            last_OH = i;
          }
          if (puzzle[i] == 'O') {
            for (int j = i - sz_q; j < i; j++) puzzle[j] = 'O';
            sz_q = 0;
            last_OH = i;
          }
        }
        pos1 = query(puzzle.substr(last_OH, 1) + "C", QUESTION);
        if (pos1 == -1) {
          for (int i = last_OH + 1; i < n; i++) puzzle[i] = puzzle[last_OH];
        } else {
          for (int i = last_OH + 1; i < pos1; i++) puzzle[i] = puzzle[last_OH];
          for (int i = pos1 + 2; i < n; i++) puzzle[i] = 'C';
        }
        query(puzzle, EXCLAMATION);
      } else {
        pos1 = query("CCC", QUESTION);
        if (pos1 != -1) {
          if (puzzle[0] == 'C') {
            query(puzzle, EXCLAMATION);
          } else {
            pos1 = query("HCCC", QUESTION);
            if (pos1 != -1) {
              for (int i = 0; i < pos1; i++) puzzle[i] = 'H';
              query(puzzle, EXCLAMATION);
            } else {
              pos1 = query("OCCC", QUESTION);
              for (int i = 0; i < pos1; i++) puzzle[i] = 'O';
              query(puzzle, EXCLAMATION);
            }
          }
        } else {
          pos1 = query("OOC", QUESTION);
          pos2 = query("HHC", QUESTION);
          if (pos1 != -1) {
            for (int i = 0; i < pos1; i++) puzzle[i] = 'O';
            for (int i = pos1 + 3; i < n; i++) puzzle[i] = 'C';
            query(puzzle, EXCLAMATION);
          } else if (pos2 != -1) {
            for (int i = 0; i < pos1; i++) puzzle[i] = 'H';
            for (int i = pos1 + 3; i < n; i++) puzzle[i] = 'C';
            query(puzzle, EXCLAMATION);
          } else {
            pos1 = query("OOOO", QUESTION);
            if (pos1 != -1) {
              query(puzzle, EXCLAMATION);
            } else {
              puzzle.assign(n, 'H');
              query(puzzle, EXCLAMATION);
            }
          }
        }
      }
    }
  }
  return 0;
}
