n=int(input())
a=list(map(int,input().split()))
r=[]
a.sort()
i=0
for j in range(n//2):
        r.append(a[j])
        r.append(a[n-j-1])
if n%2!=0:
    r.append(a[n//2])
print(*r)
