N,K = map(int,input().split())
a = list(map(int,input().split()))
s = []
for i in range(N):
    total = 0
    for j in range(i,N):
        total += a[j]
        s.append(total)
s.sort(reverse=True)
m,n = 1,1
while s[0]>=m:
    n += 1
    m *= 2
for i in range(n)[::-1]:
    t = list(filter(lambda x:x-m>=0,s))
    l = len(t)
    if l>=K:
        break
    else:
        m //= 2
n = i+1
for i in range(n):
    u = list(filter(lambda x:(x//m)%2==1,t))
    l = len(u)
    if l>=K:
        t = u[:]
        if l==K:
            break
    m //= 2
ans = t[0]
for i in range(1,K):
    ans &= t[i]
print(ans)
