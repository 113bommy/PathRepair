def ciel_dance(b,g):
    total=b+g-1
    print(total)
    for i in range(b):
        print(i+1,1)
    for i in range(2,g+1):
        print(1,i)
b,g=map(int,input().split())
ciel_dance(b,g)
