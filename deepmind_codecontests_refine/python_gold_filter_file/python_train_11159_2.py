n=int(input())
t=1
for _ in range(n):
    a=int(input())
    if a%2==0:
        print(a//2)
    else:
        if t:
            print(a//2+1)
            t=0
        else:
            print(a//2)
            t=1
