k, a, b = map(int, input().split())

if a <= b:
    if a < k:
        print(-1)
    else:
        print(1)
else:
    if a > k:
        print(1)
    else:
        answer = ((k - b - 1) // (a - b) * 2) + 1
        print(answer)
