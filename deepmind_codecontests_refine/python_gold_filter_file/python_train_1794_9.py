from sys import stdin, stdout

idx1 = 0
idx2 = 0
VALD = 0

def getminmax(n, m, a):
    l = 0
    h = 1000000009

    while l < h:
        mid = (l+h+1)//2
        exists = existsequalorbig(mid, m, a)

        if exists:
            #print(mid)
            l = mid
        else:
            h = mid-1

def existsequalorbig(mid, m, a):
    global idx1
    global idx2
    global VALD

    abw = []
    hs = set()

    for i in range(len(a)):
        v = 0
        for j in range(m):
            if a[i][j] >= mid:
                v |= 1
            v <<= 1
        v >>= 1
        if v not in hs:
            hs.add(v)
            abw.append([i, v])

    for i in range(len(abw)):
        for j in range(i, len(abw)):
            if abw[i][1] | abw[j][1] == VALD:
                idx1 = abw[i][0]
                idx2 = abw[j][0]
                return True

    #print(abw)
    #print(VALD)
    return False


#O(logA(4m+nm))
if __name__ == '__main__':
    nm = list(map(int, stdin.readline().split()))
    n = nm[0]
    m = nm[1]

    VALD = int(pow(2, m) - 1)

    a = []
    for i in range(n):
        a.append(list(map(int, stdin.readline().split())))

    getminmax(n, m, a)

    #existsequalorbig(1, m, a)

    stdout.write(str(idx1+1) + ' ' + str(idx2+1))