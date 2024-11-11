numbers = {str(i) for i in range(10)}
N, K = map(int, input().split())
*D, = map(str, input().split())
D = set(D)
available = numbers - D
ans = 0
for i in range(N, 100000):
    nums = set(str(i))
    if nums <= available:
        print(i)
        break