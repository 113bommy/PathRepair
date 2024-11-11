from collections import defaultdict
n = input()
n=int(n)
d = defaultdict(int)
c = 1
d[n] = 1
while True:
    n = n+1
    while n%10==0:
        n= n/10
    
    if d[n]==1:
        break
    else:
        d[n]=1
        c+=1

print(c)