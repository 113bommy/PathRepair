for _ in range(int(input())):
    n=int(input())
    y=0
    while n!=1:
        if n%2==0:
            n=n//2
            y+=1
        elif n%3==0:
            n=(2*n)//3
            y+=1
        elif n%5==0:
            n=(4*n)//5
            y+=1
        else:
            y=-1
            break
    print(y)






