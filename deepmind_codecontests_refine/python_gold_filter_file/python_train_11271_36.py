t = int(input())
for T in range(t):
    n = int(input())
    li = []
    st  = list(input())
    if n==1:
        print(st[0])

    elif n==2:
        print(st[1]*2)

    else:
        for i in range(2*n-1):
            if i%2==0:
                li.extend(st[i])

        # li.extend(st[2*n-2])
        for j in range(n):
            print(li[j], end="")

        print()