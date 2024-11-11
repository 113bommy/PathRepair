n = int(input())
for i in range(n):
    t = int(input())
    l = list((map(int,input().split())))
    lCopy = l.copy()
    lCopy.reverse()
    
    for i in range(len(l)):
        if l[i] == 1:
            i = i
            break

    for j in range(len(lCopy)):
        if lCopy[j] == 1:
            j = (t -j - 1)
            break

    if i == j:
        print(0)

    else:
        sum = 0
        for k in l[i+1:j]:
            sum+=k
        print(j - i - sum -1)
    
   