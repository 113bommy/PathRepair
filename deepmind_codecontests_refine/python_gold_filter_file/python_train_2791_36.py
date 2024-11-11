n,h=map(int,input().split())
l=list(map(int,input().split()))
c=[0]*n
c[1]=abs(l[0]-l[1])
for i in range(2,n):
    c[i]=min( c[j]+abs(l[i]-l[j]) for j in range(max(0,i-h),i) )
print(c[-1])
