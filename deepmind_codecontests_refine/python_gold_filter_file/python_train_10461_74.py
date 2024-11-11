(k,n,w)=map(int,input().split())
sum=0
for i in range(1,w+1):
    sum=sum+(i*k)
if sum-n>0:
    print(sum-n)
else:
    print(0)