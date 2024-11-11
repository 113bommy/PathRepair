for i in range(int(input())):
    a,b = [int(x) for x in input().split()]
    print((a^(a|b))+(b^(a|b)))
