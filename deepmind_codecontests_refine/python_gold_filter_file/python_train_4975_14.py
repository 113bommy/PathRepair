import sys
input = sys.stdin.readline

n = int(input())
ab = [tuple(map(int, input().split())) for _ in range(n-1)]

edges = {}
for i in range(1,n+1):
    edges[i] = set()

for tmp in ab:
    a,b = tmp
    edges[a].add(b)
    edges[b].add(a)

group = [[],[]]
g_flag = 0
next = {1}
while(len(next) > 0):
    tmp = list(next)
    next = set()
    for i in tmp:
        group[g_flag].append(i)
        for j in edges[i]:
            next.add(j)
            edges[j].remove(i)
    g_flag = 1- g_flag

even_n = len(group[0])
odd_n = len(group[1])

ans = [0] * (n+1)
if(even_n > n//3)&(odd_n > n//3):
    g1 = group[0][ : (n+2)//3]
    g2 = group[1][ : (n+1)//3]
    g0 = group[0][(n+2)//3 :] + group[1][(n+1)//3 :]
elif(even_n <= n//3):
    g0 = group[0]+ group[1][: n//3 - even_n]
    g1 = group[1][n//3 - even_n : (n//3 - even_n) + (n+2)//3]
    g2 = group[1][(n//3 - even_n) + (n+2)//3 :]
else:
    g0 = group[1] + group[0][: n//3 - odd_n]
    g1 = group[0][n//3 - odd_n : (n//3 - odd_n) + (n+2)//3]
    g2 = group[0][(n//3 - odd_n) + (n+2)//3 :]

# print(group)
# print(g0)
# print(g1)
# print(g2)

for i in range((n+2)//3):
    ans[g1[i]] = i*3 + 1
for i in range((n+1)//3):
    ans[g2[i]] = i*3 + 2
for i,val in enumerate(g0):
    ans[val] = (i+1) * 3

print(' '.join(map(str, ans[1:])))