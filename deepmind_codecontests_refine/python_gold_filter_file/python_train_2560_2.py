n = list(map(int,input().split(' ')))
a = list(map(int,input().split(' ')))
c = n[1]
b = []
for i in a:
    b.append((i+1)//2)
s = sum(b)
if c < s:
    print(-1)
else:
    c = c - s
    t,i = [],0
    while c > 0:
        x,y = 0,0
        for j in range(len(a)):
            if a[j] > x and j not in t:
                x = a[j]
                y = j
        k = min(a[y]//2,c)
        b[y] += k
        c -= k
        t.append(y)
    d = ' '.join(str(l) for l in b)
    print(d)
        
        
        