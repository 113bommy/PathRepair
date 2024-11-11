t = int(input())
a = []
for i in range(t):
    t2 = []
    n = []
    t1 = int(input())
    t2 = list(input())
    #print(t2)
    for j in range(t1):
        b = []
        b = t2[j:t1+j]
        #print(b)
        if len(b) == 0:
            n.append(t2[0])
        else:
            n.append(b[j])
    a.append("".join(n))

for i in a:
    print(i)