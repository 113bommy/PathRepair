for _ in range(int(input())):
    s,a,b,c=map(int,input().split())
    nofchoc=s//c
    canbuy=nofchoc//a
    t1=(canbuy*b)+nofchoc
    print(t1)