import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__

sys.setrecursionlimit(10**9)


n = int(input())
G = [[] for i in range(n)]
for i in range(n-1):
    a,b = map(int, input().split())
    a,b = a-1,b-1
    G[a].append(b)
    G[b].append(a)

flag = [0]*n
def dfs(cur, par,f):
    flag[cur] = f
    for to in G[cur]:
        if to != par:
            dfs(to, cur, f^1)

dfs(0, -1, 0)

a = sum(flag)
b = n-a

one = []
two = []
three = []
for i in range(1, n+1):
    if i%3 == 0:
        three.append(i)
    elif i%3 == 1:
        one.append(i)
    else:
        two.append(i)
k = n//3
ans = [0]*n
if k<a and k<b:
    for i in range(n):
        if flag[i]:
            if one:
                ans[i] = one.pop()
            else:
                ans[i] = three.pop()
        else:
            if two:
                ans[i] = two.pop()
            else:
                ans[i] = three.pop()
else:
    #1
    if k >= a:
        for i in range(n):
            if flag[i]:
                ans[i] = three.pop()
        res = one + two + three
        for i in range(n):
            if not flag[i]:
                ans[i] = res.pop()
    # 0
    else:
        for i in range(n):
            if not flag[i]:
                ans[i] = three.pop()
        res = one + two + three
        for i in range(n):
            if flag[i]:
                ans[i] = res.pop()
print(*ans)