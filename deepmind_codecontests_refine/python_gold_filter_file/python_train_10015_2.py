def sym(a):
    if a<=10:
        return str(a-1)
    elif (a>=11) and (a<=36):
        return chr(54+a)
    else:
        return chr(60+a)
t = int(input())
for i in range(t):
    n,m,k = map(int,input().split())
    symbol = "0"
    num = 1
    d = []
    t = [["" for j in range(m)] for o in range(n)]
    c = 0
    for j in range(n):
        r = input()
        c += r.count("R")
        d.append(r)
    minimum = c//k
    more = c%k - 1
    counter = minimum
    if more>=0:
        counter += 1
    for j in range(n//2):
        for p in range(m):
            t[2*j][p] = symbol
            if d[2*j][p] == "R":
                counter -= 1
            if counter == 0 and (num != k):
                if more>0:
                    counter = minimum + 1
                    more -= 1
                else:
                    counter = minimum
                num += 1
                symbol = sym(num)
        for p in range(m-1,-1,-1):
            t[2*j+1][p] = symbol
            if d[2*j+1][p] == "R":
                counter -= 1
            if counter == 0 and (num != k):
                if more>0:
                    counter = minimum + 1
                    more -= 1
                else:
                    counter = minimum
                num += 1
                symbol = sym(num)
    if n%2 == 1:
        for p in range(m):
                t[-1][p] = symbol
                if d[-1][p] == "R":
                    counter -= 1
                if counter == 0 and (num != k):
                    if more>0:
                        counter = minimum + 1
                        more -= 1
                    else:
                        counter = minimum
                    num += 1
                    symbol = sym(num)
    for i in t:
        print(*i, sep = "")
