N = int(input())
x = 1
y = 1
for i in range(N):
    T, A = map(int, input().split())
    p = (T + x - 1) // T
    q = (A + y - 1) // A
    x = T * max(p, q)
    y = A * max(p, q)
    #print(f"[{x} {y}]")
print(x + y)
