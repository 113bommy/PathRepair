t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split(' ')]

    if len(a) % 2 == 0:
        print("YES")

    else:
        done = False
        for i, val in enumerate(a[:-1]):
            if val >= a[i+1]:
                print("YES")
                done = True
                break
        if not done:
            if len(a) < 7:
                print("NO")
            else:
                if (len(a) - 7 + 1) % 2 == 0:
                    print("YES")
                else:
                    print("NO")
