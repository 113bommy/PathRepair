for i in range(int(input())):
    n = int(input())
    data = [int(x) for x in input().split()]
    a, b = sum(data), data[0]
    for j in range(1, n):
        b = b ^ data[j]
    if a == 2 * b:
        print(0)
        print()
    else:
        print(2)
        print(b, b + a)