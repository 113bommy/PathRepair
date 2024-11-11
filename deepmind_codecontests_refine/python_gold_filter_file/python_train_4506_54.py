for _ in range(int(input())):
    l=[int(e) for e in input().split()]
    l.sort()
    #print(l)
    x=((l[0]+l[1])**2+(l[2])**2)**(0.5)
    #print(x)
    x=(x)//1
    print(int(x))
