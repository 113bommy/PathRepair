n=int(input())
a=list(map(int,input().split()))
print(n+1)
print("1 %d 500000" %(n))
for i in range(n):
    print("2 %d %d"%(i+1,a[i]+500000-i))