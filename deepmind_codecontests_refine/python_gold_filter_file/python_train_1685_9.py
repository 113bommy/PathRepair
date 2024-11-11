for _ in range(int(input())):
    x = int(input())
    l = [int(i) for i in input().split()]
    bad = 0; c = l[x-1]

    for i in range(x-2,-1,-1):
        if(l[i] > c):
            bad+=1
        else:
            c = l[i]
    print(bad)
