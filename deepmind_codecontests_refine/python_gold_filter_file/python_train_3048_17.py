for i in range(int(input())):
    a,b=map(int,input().split())
    print((a^(a&b))+(b^(a&b)))