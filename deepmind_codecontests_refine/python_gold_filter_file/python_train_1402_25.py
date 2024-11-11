l,r=map(int,input().split())
if l%2==0 and r-l>=2:
    print(l,l+1,l+2)
elif l%2!=0 and r-l>2:
    print(l+1,l+2,l+3)
else:
    print("-1")