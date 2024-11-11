game = int (input())
for i in range(game):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    count =0
    if k >= a[n-1]:
        for i in range(1,n):
            count+=(k-a[i])//a[0]
    print(count)