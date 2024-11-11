n=int(input())
s=input()
a=[int(x) for x in input().split()]
mind=1000000001
for i in range(0,n-1):
    if s[i]=='R' and s[i+1]=='L':
        d=a[i+1]-a[i]
        if mind>d:
            mind=d
if mind==1000000001:
    print(-1)
else:
    print (mind//2)
            