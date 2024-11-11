a = list(map(lambda x: int(x), input().split()))
answer = a[2] * 2 + min(a[0], a[1]) * 2
if a[0] != a[1]:
    answer += 1
print(answer)
