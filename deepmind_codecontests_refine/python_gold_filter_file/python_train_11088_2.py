# https://codeforces.com/problemset/problem/603/A

n = int(input())
s = input()
cnt = 0
for i in range(len(s) - 1):
  if s[i] == s[i + 1]:
    cnt += 1
cnt -= 2
cnt = max(0, cnt)
print(n - cnt)