n,m,r=map(int,input().split())
s=list(map(int,input().split()))
b=list(map(int,input().split()))
if min(s)<max(b) and r>=min(s):
    k=r//min(s)
    ans=k*(max(b))+r%min(s)
    print(ans)
if min(s)>=max(b):
    print(r)
if min(s)<max(b) and r<min(s):
    print(r)