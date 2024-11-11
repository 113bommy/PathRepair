n=int(input())
l=list(map(int,input().split()))
l.reverse()
m=[2,3]
if l[0]!=2:
    print(-1)
    exit()
for i in range(1,n):
    p=l[i]
    s=-(-m[0]//p)*p
    e=(m[1]//p)*p+p-1
    if not m[0]<=s<=m[1]:
        print(-1)
        exit()
    m=[s,e]
print(*m)
