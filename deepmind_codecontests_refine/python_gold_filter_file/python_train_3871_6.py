I=lambda:map(int,input().split())
n,k=I()
a=sorted(I())
q,w,z=n//2,1,a[n//2]
for i in range(q,n-1):
    t=(a[i+1]-a[i])*w
    if k>=t:k-=t;z=a[i+1];w+=1
    else:break
print(z+k//w)