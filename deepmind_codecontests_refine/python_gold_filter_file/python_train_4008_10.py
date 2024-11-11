*a,=map(int,input().split())
*b,=sorted(map(int,input().split()))
c=min(b[0],b[a[0]]/2,a[1]/a[0]/3)
print(c*a[0]*3)
