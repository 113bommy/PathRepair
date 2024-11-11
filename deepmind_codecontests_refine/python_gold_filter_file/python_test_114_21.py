for t in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    m = min(a)
    a = [i for i in a if i!=m]
    a = a[:n//2]
    for i in a:
        print(i, m)
