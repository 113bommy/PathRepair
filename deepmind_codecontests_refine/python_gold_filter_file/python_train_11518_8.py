a = [(1,5),(3,7),(5,9),(7,11),(9,24),(11,22),(22,3),(24,1)]
b = [(2,6),(4,8),(6,10),(8,12),(10,23),(12,21),(23,2),(21,4)]
c = [(5,13),(6,14),(17,5),(18,6),(21,17),(22,18),(14,22),(13,21)]
d = [(7,15),(8,16),(19,7),(20,8),(23,19),(24,20),(16,24),(15,23)]
e = [(3,17),(4,19),(17,10),(19,9),(10,16),(9,14),(16,3),(14,4)]
f = [(1,18),(2,20),(18,12),(20,11),(12,15),(11,13),(15,1),(13,2)]


hh = list(map(int,input().split(" ")))
flag = False
#hh = [ i//4 + 1 for i in range(24)]

for i in [a,b,c,d,e,f]:
    # for j,k in i:
    #     count[j] += 1
    #     count[k] += 1
    f = True
    h = [hh[j] for j in range(24)]
    for j,k in i:
        h[j-1]= hh[k-1]
    for j in range(6):
        z = []
        for k in range(4):
            num = j * 4 + k
            z.append(h[num])
        cnt = 0
        for c in range(1,7):
            if c in z:
                cnt+=1
        if cnt != 1:
            f = False
    if f:
        flag = True
    f = True
    h = [hh[j] for j in range(24)]
    for j,k in i:
        h[k-1]= hh[j-1]
    for j in range(6):
        z = []
        for k in range(4):
            num = j * 4 + k
            z.append(h[num])
        cnt = 0
        for c in range(1,7):
            if c in z:
                cnt+=1
        if cnt != 1:
            f = False
    if f:
        flag = True




if flag :
    print("YES")
else:
    print("NO")
