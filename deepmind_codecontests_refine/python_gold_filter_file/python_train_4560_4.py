
n,k=map(int,input().split())
a = list(map(int,input().split()))
f = list(map(int,input().split()))

a.sort()
f.sort(reverse=True)

r = max(a)* max(f)
l = -1

while r-l >1:
    c = (r+l) //2
    ans=0
    for j in range(n):
        ans += max(a[j]- c // f[j] , 0)
    if ans <= k:
        r = c
    else:
        l = c

print(r)


