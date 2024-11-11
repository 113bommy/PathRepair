from collections import Counter
for _ in range(1):
    n=int(input())
    a=[int(i)-1 for i in input().split()]
    b=[int(i)-1 for i in input().split()]
    
    ai=[0]*n
    bi=[0]*n
    o=[0]*n
    for i in range(n):
        ai[a[i]]=i
        bi[b[i]]=i
    for i in range(n):
        o[(ai[i]-bi[i]+n)%n]+=1
    
    print(max(o))
   
    