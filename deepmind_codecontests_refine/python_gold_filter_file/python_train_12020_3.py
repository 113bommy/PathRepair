a=list(map(int,input().split()))
if a[2]<=a[3]/a[1]:print(a[0]*a[2])
else:
    c=a[0]//a[1]*a[3]
    a[0]%=a[1]
    c+=min(a[0]*a[2],a[3])
    print(c)
