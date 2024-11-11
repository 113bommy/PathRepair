n = int(input())
a=0
p=0
for i in range(n+1):
    a+=i
    
    
    if a == n:
        p=1
        print("YES")
        break
    
if p==0:
    print("NO")