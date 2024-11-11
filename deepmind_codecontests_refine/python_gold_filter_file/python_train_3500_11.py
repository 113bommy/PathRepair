n,k=map(int,input().split())
s=list(map(int,input().split()))
if k==1:
    print(min(s))
else:
    if k>=3:
        print(max(s))
    else:
        print(max(s[0],s[n-1]))
