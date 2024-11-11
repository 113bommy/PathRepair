t = int(input())
i = 0 
l = []
while i < t :
    i = i + 1
    l = []
    x1,y1,z1 = input().split()
    x = int(x1)
    y = int(y1)
    z = int(z1)
    l.append(x)
    l.append(y)
    l.append(z)
    l.sort()
    if l[1] != l[2]:
        print("NO")
    else:
        print("YES")
        print(l[0],l[0],l[2])
    