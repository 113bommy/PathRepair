def sum_n(x):
    return sum(map(int, list(str(x))))

a, b, c = map(int, input().split())
result = []
for s in range(1, 82):
    x = b * s ** a + c
    if 0 < x < 10 ** 9 and s == sum_n(x):
        result.append(str(x))
print(len(result))
if len(result):
    print(" ".join(result))
