
for _ in range(int(input())):
    n=int(input())
    if not n%2:
        print(n-3,2,1)
    else:
        z=n//2
        if z%2:
            print(z-2,z+2,1)
        else:
            print(z-1,z+1,1)

