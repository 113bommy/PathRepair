t = int(input())
testcases = [int(input()) for _ in range(t)]

for n in testcases:
    if n % 2 == 0:
        for i in range(n):
            if i % 2 == 0:
                print(i + 2, end=" ")
            else:
                print(i, end=" ")
    else:
        print("3 1 2", end=" ")
        for i in range(3, n):
            if i % 2 == 1:
                print(i + 2, end=" ")
            else:
                print(i, end=" ")
    print()
