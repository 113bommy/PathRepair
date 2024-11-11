n, m = input().split()
n = int(n)
m = int(m)
a = list(map(int,input().split()))
a.sort()

dp = [0]*(n+1)
s = [0]*(n+1)
for j in range(m):
    for i in range(n-j,0 ,-m):
        s[n-j] += a[i-1]
for j in range(n-m,0,-1):
    s[j] = s[j+m] - a[j+m-1]

cost = [0]*(n+1)
day=1
cnt=1
for i in range(n,0,-1):
    if(cnt%(m)==0):
        cost[n]+=day*a[i-1]
        cnt+=1
        day+=1
    else:
        cost[n]+=day*a[i-1]
        cnt+=1

for j in range(n-1,0,-1):
    cost[j]+=cost[j+1]-s[j+1]
print(*cost[1:n+1])

