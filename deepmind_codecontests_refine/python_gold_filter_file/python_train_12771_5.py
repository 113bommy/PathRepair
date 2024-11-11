a,b,c,d=map(int,input().split())
l=[]
for i in range(10):
    l.append(['A']*50)
t=0
i=0
for j in range(b):
    l[t][i]='B'
    i+=2
    if i>=50:
        t+=2
        i=0
for i in range(10):
    l.append(['A']*50)
t=10
i=0
for j in range(c):
    l[t][i]='C'
    i+=2
    if i>=50:
        t+=2
        i=0
if a==1:
    for i in range(10):
        l.append(['A'] * 50)
    t = 20
    i = 0
    for j in range(d):
        l[t][i] = 'D'
        i += 2
        if i >=50:
            t += 2
            i = 0
    print(30,50)
    r=30
else:
    if d==1:
        for i in range(10):
            l.append(['A'] * 50)
        t = 20
        i = 0
        for j in range(a):
            l[t][i] = 'D'
            i += 2
            if i >= 50:
                t += 2
                i = 0
        print(30,50)
        r=30
        for i in range(30):
            for j in range(50):
                if l[i][j]=='A':
                    l[i][j]='D'
                elif l[i][j]=='D':
                    l[i][j]='A'
    else:
        for i in range(11):
            l.append(['D'] * 50)
        t = 21
        i = 0
        for j in range(a-2):
            l[t][i] = 'A'
            i += 2
            if i >= 50:
                t += 2
                i = 0
        print(42,50)
        r=42
        for i in range(11):
            l.append(['A'] * 50)
        t = 32
        i = 0
        for j in range(d-1):
            l[t][i] = 'D'
            i += 2
            if i >= 50:
                t += 2
                i = 0
for i in range(r):
    for j in range(50):
        print(l[i][j],sep="",end="")
    print()