n = int(input())
l = []
for i in range(n):
    s = int(input())
    l.append(s)

for i in l:
    for j in range(1,181):
        x = 180/j
        a = [x*m-i for m in range(1,j-1)]
        k = False
        for s in a:
            if abs(s) <0.0001:
                k = True
        if k:
            print(j)
            break
    else:
        print('360')