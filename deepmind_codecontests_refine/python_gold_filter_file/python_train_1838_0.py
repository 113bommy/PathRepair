p, k = map(int, list(input().split()))
magic = 256
c, a, b = [], [0 for i in range(magic)], [0 for i in range(magic)] 

#
while p:
    c.append( p % k )
    p = p // k
c += [ 0 for i in range(magic - len(c)) ]

#
for i in range( len(c) ):
    if c[i] == k:
        c[i+1] += 1
        c[i] = 0

    if i & 1 and c[i]: 
        b[i] = k - c[i]
        c[i] = 0
        c[i+1] += 1        

    a[i] = c[i]

#
a.reverse()
b.reverse()
ready = False
c = []

for i in range(magic):
    if a[i] or b[i]:
        ready = True
    
    if ready:
        c.append(a[i] if a[i] else b[i])
c.reverse()

if len(c) < 1:
    print(-1)
else:
    print(len(c))
    print("".join(str(i) + ' ' for i in c))

