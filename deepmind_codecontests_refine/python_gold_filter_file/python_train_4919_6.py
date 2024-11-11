def solution():
    a,b = input().split()
    b = int(b)-1
    while  b:
        b-=1
        temp = a
        mi = 9; ma = 0
        for i in temp:
            mi = min(mi, int(i))
            ma = max(ma,int(i))
        if mi == 0 :
            return a
        a = str(int(a)+mi*ma)
    return a

    


for _ in range(1):
    a,b = map(int,input().split())
    li = []
    counter = 0
    for i in range(a-1):
        li.append('1')
        counter += 1
    li.append(str(b-counter))
    if a>b//2 or counter+1 >= b-counter:
        print("NO")
    else:
        print("YES")
        print(' '.join(li))
        print(counter+1)

