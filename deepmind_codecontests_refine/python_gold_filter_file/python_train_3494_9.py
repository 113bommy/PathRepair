from collections import defaultdict

n = int(input())

d = defaultdict(list)

def update(a,b,c,i):
    global d
    u = len(d[a,b])
    if u == 0:
        d[a,b].append((c,i+1))
    elif u == 1:
        if i+1 == d[a,b][0][1]:
            return
        if c >= d[a,b][0][0]:
            d[a,b].append((c,i+1))
        else:
            u = d[a,b][0]
            d[a,b][0] = (c,i+1)
            d[a,b].append(u)
    else:
        u1 = d[a,b][0][1]
        u2 = d[a,b][1][1]

        if i + 1 != u1 and i + 1 != u2:
            if c > d[a,b][0][0]:
                if d[a,b][0][0] == d[a,b][1][0]:
                    d[a,b][1] = (c,i+1)
                elif c > d[a,b][1][0]:
                    d[a,b][0],d[a,b][1] = d[a,b][1],(c,i+1)
                else:
                    d[a,b][0] = (c,i+1)
            

for i in range(n):
    a,b,c = [int(j) for j in input().split()]
    if a>b:
        a,b = b,a
    if b>c:
        b,c = c,b
    if a>b:
        a,b = b,a
        
    update(a,b,c,i)
    #print(d)
    update(b,c,a,i)
    #print(d)
    update(a,c,b,i)
    #print(d)

max = 0
k = 0

for i in d.keys():
    u = min([i[0],i[1],sum([j[0] for j in d[i]])])
    if u > max:
        max = u
        k = d[i]

print(len(k))

for i in k:
    print(i[1],end= ' ')
    
    
