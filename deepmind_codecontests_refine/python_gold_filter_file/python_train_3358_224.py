t = int(input())

for _ in range(t):
    n = int(input())

    for i in range(n):
        print(1 if i%2==0 else 3, end=" ")
    print("")