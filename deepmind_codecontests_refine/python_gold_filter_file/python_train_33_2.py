a,b,c=map(int,input().split())
d=b*b-4*a*c
if a==0:
    if b==0 and c==0: print(-1)
    elif b==0: print(0)
    else: print(f'1\n{-c/b}')
elif d<0: print(0)
else:
    s=sorted({(-b+d**.5)/(2*a),(-b-d**.5)/(2*a)})
    print(len(s))
    for i in s:
        print(f'{i:.5f}')