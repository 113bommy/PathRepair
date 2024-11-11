# cook your dish here
mod = 10**(9)+7
import sys
input = sys.stdin.readline
#t=1
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    m=min(a)
    ans=[]
    for i in range(n):
        if a[i]!=m:
            ans.append([a[i],m])
        if len(ans)==n//2:
            break
    for i in range(len(ans)):
        print(ans[i][0],ans[i][1])
            
    
        
    