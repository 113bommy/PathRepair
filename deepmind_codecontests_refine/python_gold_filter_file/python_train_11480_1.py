import sys
input = sys.stdin.readline
 
t = int(input())
 
for _ in range(t):
    x = int(input())
    l = list(map(int,input().split()))
 
    ans = 0 
    tmp = 0
    
    last = l[0]
    
    for i in range(1,x):
        if l[i] < l[i-1]:
            tmp = max(tmp, last-l[i])
        else:
            last = l[i]
            ans += tmp
            tmp = 0
            
    ans += tmp
            
    print(ans)