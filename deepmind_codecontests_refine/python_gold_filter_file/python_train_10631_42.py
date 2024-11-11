n=int(input())
arr=list(map(int,input().split()))
print(n+1)
print(1,n,500000)
for i in range(n):
    print(2,i+1,arr[i]+500000-i)
