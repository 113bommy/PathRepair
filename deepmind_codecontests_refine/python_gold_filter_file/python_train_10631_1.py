n=int(input())
l=list(map(int,input().split()))
print(n)
print(1,n,2*n)
for i in range(n-1):
    print(2,i+1,l[i]+2*n-i)
        