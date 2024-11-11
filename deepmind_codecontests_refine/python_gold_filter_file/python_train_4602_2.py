def isInt(n):
    return int(n) == float(n)
for _ in range(int(input())):
    p1,q1,p2,q2 = 0,0,0,0
    n1 = int(input())
    a1 = list(map(int, input().split()[:n1]))
    n2 = int(input())
    a2 = list(map(int, input().split()[:n2]))
    for i in range(len(a1)):
        if a1[i] % 2 == 0:
            p1 += 1
        else:
            q1 += 1
    for i in range(len(a2)):
        if a2[i] % 2 == 0:
            p2+=1
        else:
            q2+=1
    print(p1*p2+q1*q2)