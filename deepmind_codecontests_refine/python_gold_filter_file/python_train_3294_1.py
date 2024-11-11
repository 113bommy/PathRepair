t = int(input())
while t > 0:
    n, k = map(int, input().split(" "))
    x = list(map(int, input().split(" ")))
    #print(x)
    nList = list(0 if i not in x else 1 for i in range(1, n + 1))
    #print(nList)
    s = 1
    while 0 in nList:
        nList = [1 if ((i > 0 and nList[i-1] == 1) or (i < len(nList) - 1 and nList[i+1] == 1)) else nList[i] for i in range(len(nList))]
        #print(nList)
        s += 1
    print(s)
    t -= 1
