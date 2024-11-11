def ans():
    N=input().split()
    A=int(N[0])
    B=int(N[1])
    C=int(N[2])
    if A==B:
        print(C*2+A+B)
    else:
        print(C*2+min(A,B)*2+1)
ans()