import sys

d = sys.stdin.readline()
while d:
    a,b,c,d,e,f = map(int,d.split())
    inv = 1/(a*e - b*d)
    iA = [[e,-b],[-d,a]]
    B = [c,f]
    sol = list()
    for i in range(2):
        tmp = 0
        for j in range(2):
            tmp += inv*iA[i][j] * B[j]
        sol.append(tmp)
    print("%.3f %.3f"%(sol[0],sol[1]))

    d = sys.stdin.readline()