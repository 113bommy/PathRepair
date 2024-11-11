n,x,y = list(map(int,input().split()))
ans = [0]*(n-1)
for i in range(n-1):
    for j in range(i+1,n):
        ans[min(j-i,1+abs(x-1-i)+abs(y-1-j))-1]+=1
for num in ans:
    print(num)