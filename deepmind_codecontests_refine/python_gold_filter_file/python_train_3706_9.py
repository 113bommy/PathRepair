m=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]
a,b=[int(w) for w in input().split()]
for i in m:
    if i==a:
        x=m.index(a)
        if b in m:
            y=m.index(b)
            if y==x+1:
                print('YES')
                break
            else:
                print('NO')
                break
        else:
            print('NO')