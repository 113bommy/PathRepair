for u in range(int(input())):
    n,a,b=map(int,input().split())
    x=['a']*a
    if b!=1:
        for i in range(b-1):
            x[i]=chr(ord('a')+i+1)
    ans= x*(n//a)+x[:n%a]
    print("".join(ans))