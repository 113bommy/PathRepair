n,s=map(int,input().split())
l=list(map(int,input().split()))
if(sum(l)-max(l)<=s):
    print("YES")
else:
    print("NO")