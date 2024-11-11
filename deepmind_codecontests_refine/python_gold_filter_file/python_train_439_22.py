for _ in range(int(input())):
    s,t=map(int,input().split())
    print(min(s,t,(s+t)//3))