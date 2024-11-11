t=int(input(""))
i=0
while i<t:
    n, m=[int(n) for n in input().split()]
    if n==1:
        print(0)
    elif n<3:
        print(m)
    else:
        print(2*m)
    i+=1
