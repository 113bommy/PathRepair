T = int(input())
for _ in range(T):
    n = int(input())
    if n <= 3:
        print(-1)
    else:
        left = []
        for i in range(1, n + 1, 2):
            left.append(i)
        right = []
        right.append(4)
        right.append(2)
        for i in range(6, n + 1, 2):
            right.append(i)
        right.reverse()

        for i in left:
            right.append(i)
        
        for i in right:
            print(i, end = " ")
        print("")