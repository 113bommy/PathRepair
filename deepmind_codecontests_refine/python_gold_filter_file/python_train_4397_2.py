### A. Kuroni and the Gifts
for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    b=[int(y) for y in input().split()]
    a=sorted(a)
    b=sorted(b)
    print(*a)
    print(*b)