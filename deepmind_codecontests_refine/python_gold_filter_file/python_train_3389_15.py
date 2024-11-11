# 707A => Brain's Photos
# https://codeforces.com/problemset/problem/707/A

x = False
n, m = map(int, input().split())
for _ in range(n):
    row = input().split()
    if not x:
        for i in row:
            if i not in ["B", "W", "G"]:
                x = True
if x:
    print("#Color")
else:
    print("#Black&White")