I=lambda:list(map(int,input().split()))
a,x=I(),I()
s,z=0,0
for i in range(3):
    if a[i]>x[i]:s+=(a[i]-x[i])//2
    else:z+=x[i]-a[i]
print("NO" if z>s else"YES")