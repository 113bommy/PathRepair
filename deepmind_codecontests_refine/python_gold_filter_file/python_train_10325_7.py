x=int(input())
a=list(map(int,input().split()))
c=sum(a)
d=max(a)
if d<=c//2 and x>1 and c%2==0:
    print("YES")
else:
    print("NO")