g=int(input())
for i in range(g):
    n=int(input())
    if n==0:
        print(4)
    elif n==1:
        print(3)
    elif n==2:
        print(2)
    elif n%2==0:
        print(0)
    else:
        print(1)
