from math import *
sInt = lambda: int(input())
mInt = lambda: map(int, input().split())
lInt = lambda: list(map(int, input().split()))
 
t= sInt()
 
 
for _ in range(t):
    n = sInt()
    ans = [0 for c in range(26)]
    for i in range(n):
        a = input()
        a = list(a)
        for j in range(len(a)):
            f = ord(a[j])
            ans[f-97] += 1
    #print(ans)
    d = 0
    for i in range(26):
        if ans[i]%n!=0:
            d = 1
            break
    if d==0:
        print("YES")
    else:
        print("NO")
    
        
         
        