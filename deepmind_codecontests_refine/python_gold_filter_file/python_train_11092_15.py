n=int(input())
s=input()
l=list(map(int,input().split()))
res=float("inf")
ans=False
if n==1:
    print(-1)
else:
    for i in range(n-1):
        if (s[i]=="R" and s[i+1]=="L"):
            ans=True
            res=min(res,abs(l[i]-l[i+1])//2)
    if not ans:
        print(-1)
    else:
        print(res)