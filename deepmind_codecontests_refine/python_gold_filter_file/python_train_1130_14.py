import bisect

def wantp(p,day):

    for i in range(len(db)):
        i = len(db)-1-i

        if day & (2 ** i) > 0:
            p = db[i][p]

        #print (day,i)

    return p


N = int(input())
x = list(map(int,input().split()))
L = int(input())

able = []

for i in range(N):

    able.append(bisect.bisect_right(x,x[i] + L) - 1)


db = [able]

while min(db[-1]) != N-1:

    new = []

    for i in range(N):

        new.append(db[-1][db[-1][i]])

    db.append(new)


Q = int(input())

for loop in range(Q):

    a,b = map(int,input().split())
    if a > b:
        t = a
        a = b
        b = t
    a -= 1
    b -= 1

    l = 0
    r = 2 ** len(db)

    while r-l != 1:

        m = (l+r) // 2

        np = wantp(a,m)
        #print (a,m,np)

        if np < b:
            l = m
        else:
            r = m

    print (r)
