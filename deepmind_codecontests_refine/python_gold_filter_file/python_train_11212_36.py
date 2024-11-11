n = int(input())
B = list(map(int,input().split()))

if n == 1:
    print(-1)
elif n == 2:
    if B[0] == B[1]:
        print(-1)
    else:
        print(1)
        print(1)
else:
    print(1)
    print(B.index(min(B))+1)

        

