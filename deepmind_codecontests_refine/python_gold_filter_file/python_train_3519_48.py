N,K = map(int,input().split(" "))
V = list(map(int,input().split(" ")))

maxcost = min(N,K)
o = []

A = 0
while A <= maxcost:
    B = 0
    while A + B <= maxcost:
        a = V[:A]+V[N-B:]
        b = sorted(list(filter(lambda x:x<0,a)))[:K-A-B]
        #print(a,b)
        o.append(sum(a)-sum(b))
        B += 1
    A += 1

print(max(o))