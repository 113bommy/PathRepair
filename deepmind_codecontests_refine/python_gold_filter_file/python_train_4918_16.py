for u in range(int(input())):
    n,x,y=map(int,input().split())
    l='abcdefghijklmnopqrstuvxwyz'
    z=n//y
    r=n%y
    s=l[:y]*z+l[:r]
    print(s)
