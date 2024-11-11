for _ in range(int(input())):
    l = list(input())
    d = 0
    index = len(l)
    flag = 0
    for i in range(len(l)-1,-1,-1):
       if i < index - d:
           if l[i] == "R":
               d = index - i
               index = i
       elif l[i] == "R":
           index = i

    if 0 < index-d+1:
        d = index - i +1



    print(d)

