mp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
imp=0
t = int( input())
while t>0:
    imp = 0
    z = input().split()
    r = int(z[0])
    c = int(z[1])
    k = int(z[2])
    i = 0
    j = 0
    inp = []
    rice = 0;
    while i<r:
        a = input()
        for j in a:
            if(j == 'R'):rice += 1
        inp.append(a)
        i += 1
    i = 0
    j = 0
    res = [[0 for _ in range(c)] for _ in range(r)]
    perChicken = rice // k
    extra = rice % k
    curr = perChicken
    sign = 1
    if(extra > 0):
        curr += 1
        extra -= 1
    while i < r:
        if(inp[i][j] == 'R') :
         #   print("1")
            if(curr == 0):
                curr = perChicken
                if(extra>0):
                    curr += 1
                    extra -= 1
                imp += 1

            curr -= 1
            res[i][j] = mp[imp]
        else:
            res[i][j] = mp[imp];
        j += (sign) * 1
        if(j>=c):
            sign = (-1) * sign
            j = c-1
            i += 1
        elif (j<0):
            sign = (-1) * sign
            j = 0
            i += 1
    for _ in range(r):
        for __ in range(c):
            print(res[_][__],end='')
        print()
    t -= 1

