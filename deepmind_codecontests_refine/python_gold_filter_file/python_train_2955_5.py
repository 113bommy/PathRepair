n=int(input())
a=list(map(int,input().split()))
for i in range(2,n):
    if (a[i]-a[i-1])*(a[i-1]-a[0])<0:
        print(3,1,i,i+1)
        exit()
print(0)
