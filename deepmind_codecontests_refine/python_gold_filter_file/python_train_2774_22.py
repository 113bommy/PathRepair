# cook your dish here
n,k = map(int,input().split())
l = list(map(int,input().split()))
c = 10**19
ind = -1
for i in range(k):
    if l[i] <= n:
        if (n%l[i]) < c:
            c = n%l[i]
            ind = i+1
if ind == -1:
    print(1,0)
else:
    print(ind,n//l[ind-1])
  
