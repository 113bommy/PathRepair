n,k = map(int,input().split())
a = list(map(int,input().split()))
b = [(a[i],i) for i in range(n)]
b.sort(reverse = True)
index = []
for i in range(k):
    index.append(b[i][1])
index.sort()
index.pop()
index.append(n-1)
ans = 0
for i in range(k):
    ans += b[i][0]
print(ans)
pre = -1
ans = []
for x in index:
    ans.append(x-pre)
    pre = x
print(*ans)