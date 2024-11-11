m,n=list(map(int,input().split()))
count=0
while m <= n:
    m*=3
    n*=2
    count+=1
print(count)

