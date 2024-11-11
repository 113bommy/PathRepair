for _ in range(int(input())):
    n=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    i = 0
    for aa in range(1,len(a)):
        if aa == 1:
            i = a[aa] - a[aa-1]
        elif aa < len(a):
            if a[aa] - a[aa-1] < i:
                i = a[aa] - a[aa-1]
    print(i)
