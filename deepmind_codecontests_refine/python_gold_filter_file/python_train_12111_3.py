n,k=map(int,input().split())
ar=list(map(int,input().split()))
ar=sorted(ar)
summ=0
flag=True
for i  in range(n):
   if (i+1)*n>=k:
     break

x=ar.count(ar[i])
c=ar.index(ar[i])
y=((k-1)-c*n)//x
print(ar[i],ar[y])

