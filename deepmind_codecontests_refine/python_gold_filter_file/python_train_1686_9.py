n = int(input().strip())
n2 = n**2
L = [x for x in range(1,n2 + 1)]
M = [ [] for i in range(n)]
i = 0
t = 0
while i < n2:
    if t%2 == 0:
        for j in range(n):
            M[j].append(str(L[i]))
            i += 1
    else:
        for j in range(n-1,-1,-1):
            M[j].append(str(L[i]))
            i += 1
    t += 1

for i in M:
    print(" ".join(i))
