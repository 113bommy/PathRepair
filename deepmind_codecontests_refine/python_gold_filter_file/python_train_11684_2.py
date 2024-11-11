for _ in range(int(input())):
    n = int(input())

    arr = list(map(int, input().split()))

    res = 0
    done = False
    for i in range(n):
        s = 0
        sub = []
        for j in range(i, n):
            s += arr[j]
            sub.append(j+1)
            if(s%2 == 0):
                done = True
                break

        if(done):
            break

    if(done):
        print(len(sub))
        print(*sub)
    else:
        print(-1)