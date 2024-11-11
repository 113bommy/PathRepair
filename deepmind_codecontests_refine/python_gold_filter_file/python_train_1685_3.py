user_input = int(input())
for i in range(user_input):
    a = int(input())
    b = list(map(int, input().split()))
    count = 0
    minimum = b[-1]
    for j in range(a-2, -1, -1):
        if b[j] > minimum:
            count += 1
        minimum = min(b[j], minimum)
    print(count)
