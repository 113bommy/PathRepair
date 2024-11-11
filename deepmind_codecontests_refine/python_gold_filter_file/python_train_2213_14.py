import sys;input=sys.stdin.readline
N, M = map(int, input().split())
a, k, b = map(int, input().split())
X = [0] + list(map(int, input().split())) + [0]
Y = [0] + list(map(int, input().split())) + [0]
j = 0
tmp = []
S = []
for i in range(N+2):
    tmp.append(X[i])
    if Y[j] == X[i]:
        if len(tmp) > 2:
            S.append(tmp)
        j += 1
        tmp = [X[i]]
    else:
        pass
if j != M+2:
    print(-1)
    sys.exit()
R = 0
for l in S:
#    print(l)
#    print(l[1:-1])
    mx = max(l[1:-1])
    lc = (len(l)-2)
    if max(l[0], l[-1]) > mx:
        if b * k > a:
            R += a * (lc//k) + b * (lc%k)
        else:
            R += lc*b
    else:
        if lc < k:
            print(-1)
            sys.exit()
        if b * k > a:
            R += a * (lc//k) + b * (lc%k)
        else:
            R += (lc-k)*b+a
print(R)
