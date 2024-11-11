test=int(input())
for t in range (0,test):
    n, m=map(int,input().split())
    a = list(map(int,input().split()))
    if n>m or n==2:
        print(-1)
    else:
        print(sum(a)*2)
        for i in range (0,m-1):   
            print(i+1,i+2)
        print(n,1)
