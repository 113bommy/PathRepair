x = [int(x) for x in input().split()]
m = x[1]
n = x[0]
d = []
t=0
s= []
for i in range(n):
    p = [int(x) for x in input().split()]
    d.append(p)
for i in range(n):
    k = d[i][0]-d[i][1]
    t+=d[i][0]
    s.append(k)
o = t-m
s = sorted(s, key=int, reverse=True)
if(sum(s)<o):
    print(-1)
else:
    u=0
    i=0
    while(u<o):
        u+=s[i]
        i+=1
    print(i)

        
    
    
    
    