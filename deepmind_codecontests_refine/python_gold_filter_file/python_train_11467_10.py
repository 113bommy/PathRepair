n,m = map(int,input().split())
a = list(map(int,input().split()))
ans=1
su = sum(a)
a.sort(reverse=True)
s = [0]*n
s[0] = a[0]
for i in range(1,n):
    s[i] = s[i-1]+a[i]

def pos(d):
    i=d
    while i<=n:
        k = i//d
        neg = k*i-((k*(k+1))//2)*d
        if(s[i-1]-neg >= m):
            return True
        i+=1
    return False



if(su < m):
    ans = -1
    print(ans)

else:
    first = 0
    last = n

    while first<last-1:
        midpoint = (first + last)//2
        if pos(midpoint):
            last = midpoint
        else:
            first = midpoint

    print(last)
