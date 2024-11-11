from sys import stdin

n = int(input())
l = list(map(int, stdin.readline().split()))
l.sort()
flag = 0
for i in range(n):
    if l[n - i - 1] == l[n + i]:
        flag = 1
        break
if flag:
    print("NO")
else:
    print("YES")
