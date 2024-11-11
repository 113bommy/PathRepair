import sys
input=sys.stdin.readline
I=lambda:list(map(int,input().split()))
n,x=I()
l=I()
ans=0
l.sort()
while l[((n+1)//2-1)]!=x:
    l.append(x)
    l.sort()
    n+=1
    ans+=1
print(ans)
    