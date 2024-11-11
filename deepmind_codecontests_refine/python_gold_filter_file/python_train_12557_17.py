def d(n):
    sm=0 
    while n:
        sm+=n%10 
        n=n//10 
    return sm  
n=int(input())
cnt = 0 
ans=[] 
for j in range(max(n-90,0),n+1,1):
    if j+d(j)==n:
        cnt+=1
        ans.append(j)
print(cnt)
print(*ans)