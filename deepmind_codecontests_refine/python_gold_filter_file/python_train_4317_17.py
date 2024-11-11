def binarysearch(a,x):
   lo=0
   hi=len(z)-1
   while lo < hi:
       mid = (lo + hi) // 2
       if a[mid]==x:
           return  mid+1
       if a[mid] < x:
           lo = mid + 1
       else:
           hi = mid
   return lo+1
n=int(input())
x=[int(i) for i in input().split()]
z=[]
z.append(x[0])
for i in range(1,n):
    z.append(x[i]+z[i-1])
a=int(input())
for i in input().split():
    i=int(i)
    print(binarysearch(z,i))




