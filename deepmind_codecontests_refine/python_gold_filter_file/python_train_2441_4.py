n, m, k = [int(k) for k in input().split()]
total = n * m
length = [int(total/k)]*(k-1)
length.append(total - (int(total/k))*(k-1))
#print(length)
table =[[0]*(n+1) for _ in range(m+1)]
i = 1


path = []
for r in range(1, m+1):
    if r % 2 == 0: #odd rows, go forward
        for c in range(n, 0,-1):
            path.append(c)
            path.append(r)
    else: #even rows, go backwards
        for c in range(1, n+1):
            path.append(c)
            path.append(r)

#print(path)
i = 0    
for l in length:
    print(l, end = " ")
    s = ""
    for x in path[i:i+2*l]:
        s += str(x) + " "
    print(s)
    #print(path[i:i+2*l], end = " ")
    i = i+2*l
   