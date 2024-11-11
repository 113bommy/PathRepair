l,r=list(map(int,input().split()))
if r-l<=1:
    print(-1)
elif r-l==2 and l%2!=0:
    print(-1)
else:
    if l%2==0:
        print(l,l+1,l+2)
    else:
        print(l+1,l+2,l+3)