import math
for _ in range(int(input())):
    n = int(input())*2
    a = list(map(int,input().split()))
    o = []
    e = []
    for i in range(n):
        if(a[i]%2==0):
            e.append(i+1)
        else:
            o.append(i+1)
    for i in range(n//2-1):
        if(len(e)>1):
            print(e[-1],e[-2])
            e = e[:-2]
        elif(len(o)>1):
            print(o[-1],o[-2])
            o = o[:-2]
            
