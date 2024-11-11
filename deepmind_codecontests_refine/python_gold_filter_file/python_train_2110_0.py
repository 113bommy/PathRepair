from sys import stdin

t = int(input())

for _ in range(t):
    n = int(input())
    ans = []
    for i in range(n,0,-1):
        ans.append(i)
    print(*ans)