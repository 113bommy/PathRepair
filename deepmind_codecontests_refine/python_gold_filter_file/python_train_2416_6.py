for _ in range(int(input())):
    n=int(input())
    l=list()
    for i in range(n):
        l.append(input())
    # l.sort()
    c=0
    for i in range(n):
        x=l[i]
        if x in l[0:i] or x in l[i+1:]:
            y=0
            f=0
            while y<4:
                for z in range(10):
                    p=(x[0:y]+str(z)+x[y+1:])
                    if p not in l[0:i] and p not in l[i+1:]:
                        l[i]=p
                        c+=1
                        f=1
                        break
                if f==1:
                    break
                y+=1
    print(c)
    for i in l:
        print(i)
