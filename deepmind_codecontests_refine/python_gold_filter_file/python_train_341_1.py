t=int(input())
for _ in range(t):
    n = int(input())
    rc = []
    r = list(map(int, input().split()))
    c = list(map(int, input().split()))
    for i in range(n):
        rc.append([r[i], c[i]])
    rc.sort()
    if rc[0]!=[1,1]:
        rc.insert(0,[1,1])
        n+=1
    s=0
    for i in range(n-1):
        if (rc[i][1]-rc[i][0] == rc[i+1][1]-rc[i+1][0]) and (rc[i][1]+rc[i][0])%2==0:
            s+=rc[i+1][0]-rc[i][0]
        elif (rc[i][1]-rc[i][0] == rc[i+1][1]-rc[i+1][0]) and  (rc[i][1]+rc[i][0])%2!=0:
            s+=0
        elif (rc[i][1]+rc[i][0])%2==0:
            s+=((rc[i+1][0]-rc[i][0])-(rc[i+1][1]-rc[i][1]))//2
        else:
            s += ((((rc[i + 1][0] - rc[i][0]) - (rc[i + 1][1] - rc[i][1]))+1) // 2)
    print(s)