n=int(input())
l=list(map(int,input().strip().split()))
l.sort()
a=l[n-1]-l[0]
b=l[2*n-1]-l[n]
ans1=a*b
min1=1000000000000000000000
for i in range(1,n):
    s=l[i+n-1]-l[i]
    if (s<min1):
        min1=s
ans2=min1*(l[2*n-1]-l[0])
if (ans1<ans2):
    print (ans1)
else:
    print (ans2)
