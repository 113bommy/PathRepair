D = int(input())
c = list(map(int, input().split()))
s = [list(map(int, input().split())) for _ in range(D)]

for i in range(D):
    print(i % 26 + 1)
