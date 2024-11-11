n,m = input().split()
n =int(n)
m = int(m)
arr = [int(x) for x in input().split()]
min = 1000000000000
ans= -1
for i in range(m):
       sum=0
       for j in range(i,n,m):
             sum=sum+arr[j]
       if sum<min:
             min=sum
             ans=i
print(ans+1)
                      
    

