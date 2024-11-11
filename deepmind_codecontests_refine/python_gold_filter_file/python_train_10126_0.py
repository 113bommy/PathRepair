t = int(input())
for _ in range(t):
    n = int(input())
    l1 =[]
    for i in range(n):
        l1+=list(input())
    #print(l1)
    ruined=0
    for j in list(set(l1)):
        if l1.count(j)%n:
            ruined=1
            break
    if ruined:
        print("NO")
    else:
        print("YES")











