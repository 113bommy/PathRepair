n,r,a = map(int,input().split(' '))
s = 0 
arr = []
for _ in range(n):
    u,v = map(int,input().split(' '))
    if u<r:
        arr.append([u,v])
    s = s + u 
x = n*a - s 
if x<=0:
    ans = 0 
else:
    ans = 0 
    arr.sort(key=lambda x:x[1])
    for item in arr:
        if r - item[0]<x:
            ans = ans + (r-item[0])*item[1]
            x = x - (r-item[0])
        else:
            ans = ans + x*item[1]
            x = 0 
            
        if x==0:
            break
print(ans)
        
    