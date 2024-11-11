for _ in range(int(input())):
    w=input()
    n=len(w)
    if n<=10:
        print(w)
    else:
        print(w[0]+str(n-2)+w[-1])