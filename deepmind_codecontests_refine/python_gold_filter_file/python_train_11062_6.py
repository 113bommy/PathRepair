n=int(input())
while n:
    m=int(input())
    arr=list(map(int,input().split()))
    i=m-1
    while i>0 and arr[i]<=arr[i-1]:
        i-=1
    i-=1
    while i>0 and arr[i]>=arr[i-1]:
        i-=1
        
    print(max(i,0))
    n-=1