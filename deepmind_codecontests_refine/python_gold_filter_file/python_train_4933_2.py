n,s,t=map(int,input().split())
arr=list(map(int,input().split()))
for i in range (n):
    if(s==t):
        print(i)
        exit()
    s=arr[s-1]
print(-1)