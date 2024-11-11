l  = list(map(int,input().split()))
a,b,c,d = l[0],l[1],l[2],l[3]
m = max(3*a/10, a - a/250*c)
v = max(3*b/10, b - b/250*d)
if m >v:
    print('Misha')
elif m == v:
    print('Tie')
else:
    print('Vasya')
