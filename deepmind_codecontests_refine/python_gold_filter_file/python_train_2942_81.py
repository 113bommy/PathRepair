for ti in range(int(input())):
    n=int(input())
    if n>2 and n%2==1:
        print(n//2+1)
    elif n>2 and n%2==0:
        print(n//2)
    else:
        print(1)