n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
b.reverse()
p = 1
c = 0
d = 0
for i in range(n):
    if a[i] == b[i]:
        v = a[i]
        h = i
        p = 0
        break
if p == 1:
    print('Yes')
    for i in range(n):
        print(b[i],end = ' ')
else:
    for i in range(n):
        if a[i] != v and b[i] != v:
            c += 1
        if b[i] == a[i] :
            d += 1
    if c < d:
        print('No')
    else:
        print('Yes')
        o = 0
        for i in range(n):
            if a[i] != v and b[i] != v:
                b[i],b[h+o] = b[o+h],b[i]
                o += 1
                if o == d:
                    break
        for i in range(n):
            print(b[i],end = ' ')