a = int(input())
b = list(map(int, input().split()))
mark = 0
answer = list()
for x in range(a):
    if b[a - x - 1] > mark:
        answer.append(0)
        mark = b[a - x - 1]
    else:
        answer.append(mark - b[a - x - 1] + 1)
for x in range(a):
    print(answer[a - x - 1], "", end="", flush=True)