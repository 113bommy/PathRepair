for _ in range(int(input())):
    l = list(map(int,input().split()))
    a1 = l[0] ; a2 = l[1] ; a3 = l[-1] - a1 - a2 ;
    print(a1,a2,a3, end = " ")
    print()