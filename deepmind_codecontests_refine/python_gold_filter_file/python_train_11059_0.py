for _ in range(int(input())):
    l = str(input())
    b = list()
    try:
        k = l.index("R")
        for i in range(l.index("R") +1 , len(l)):
            if l[i] == "R":
                b.append(i-k)
                k = i
        b.append(l.index("R")+1)
        for j in range(len(l)):
            if l[len(l) - 1 -j] == "R":
               b.append(j+1)
               break
        print( max(b))
    except:
        print(len(l) + 1)

