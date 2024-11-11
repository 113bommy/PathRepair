n = int(input())
l = [int(x) for x in input().split()]

if n == 1:
    print(-1)

elif n==2:
    if l[0] == l[1]:
        print(-1)

    else:
        print(1)
        print(1)

else:
    m = min(l)
    i = l.index(m)


    print(n-1)
    for x in range(n):
        if x!= i:
            print(x+1 ,end=" ")