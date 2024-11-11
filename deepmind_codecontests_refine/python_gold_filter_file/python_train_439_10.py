for i in range(int(input())):
    m,n=map(int,input().split())
    print(min(m,n,(m+n)//3))