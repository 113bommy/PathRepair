A, B, K = map(int, input().split())
x = A
while x < A+K and x <= B:
    print(x)
    x += 1
for y in range(max(x, B-K+1), B+1):
    print(y)