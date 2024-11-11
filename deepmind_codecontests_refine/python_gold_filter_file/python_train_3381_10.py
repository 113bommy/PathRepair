a,b,s=[int(w) for w in input().split()]
t=abs(a)+abs(b)
if t==s or s>t and (s-t)%2==0:
    print('YES')
else:
    print('NO')