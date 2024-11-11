k,n = input().split()
lis = input().split()
lis2=[]
n = int(n)
k = int(k)
for i in range(0,n):
    lis[i]=int(lis[i])
lis.sort()
for i in range(0,n-k+1):
    lis2.append(lis[i+k-1]-lis[i])
print(min(lis2))