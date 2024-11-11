

# p = 1000
# c = 1000

# w = [[0,i+1,2] for i in range(p)]

n = int(input())
while(n):
    [p,c] =  input().split();
    p = int(p)
    c = int(c)
    w = [[int(i),j+1,2] for i,j in zip(input().split(),range(p)) ]


    n -= 1
    w.sort(reverse=True)

    if (c < p or p < 3):
        print(-1)
        continue

    s = []
    connected = []
    t = 0

    while len(w):
        if (len(w) > 1 or w[-1:][0][2] == 0):
            connected.append(w.pop());


        if (len(w) == 0): break
        cur =  w[-1:][0]
        for i in connected:
            if (i[2]):
                i[2] -= 1
                cur[2] -= 1
                s.append([cur[1],i[1]])
                t += cur[0] + i[0]

                break


    print(t)
    for i in s:
        print(str(i[0]) + " " + str(i[1]))
