q=[input() for i in range(4)]
def f(a,s):
    b=True
    w=0
    for i in range(3):
        if q[a+i][s+i]=='x':
            w+=1
        elif q[a+i][s+i]=='o':
            b=False
            break
    return b&(w==2)
def d(a,s):
    b=True
    w=0
    for i in range(3):
        if q[a-i][s+i]=='x':
            w+=1
        elif q[a-i][s+i]=='o':
            b=False
            break
    return b&(w==2)

def g(a,s):
    b=True
    w=0
    for i in range(3):
        if q[a+i][s]=='x':
            w+=1
        elif q[a+i][s]=='o':
            b=False
            break
    return b&(w==2)
def h(a,s):
    b=True
    w=0
    for i in range(3):
        if q[a][s+i]=='x':
            w+=1
        elif q[a][s+i]=='o':
            b=False
            break
    return b&(w==2)


b=f(0,0)|f(1,1)|f(1,0)|f(0,1)|d(3,0)|d(3,1)|d(2,0)|d(2,1)|g(0,0)|g(1,0)|g(0,1)|g(1,1)|g(0,2)|g(1,2)|g(0,3)|g(1,3)|h(0,0)|h(0,1)|h(1,0)|h(1,1)|h(2,0)|h(2,1)|h(3,0)|h(3,1)
print('YES' if b else 'NO')
