n = int(input())
a = list(map(int,input().split()))
a.sort()
k, l = [],[]
for i in range(n):
    if a[i]%2 == 1:
        k.append(a[i])
    else:
        l.append(a[i])
if abs(len(k)-len(l)) > 1:
    if len(k) > len(l):
        print(sum(k[:(len(k)-len(l)-1)]))
    else:
        print(sum(l[:(len(l)-len(k)-1)]))
else:print(0)  
  
        
