t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    answer = []
    idx = -1
    for i in range(n):
        if a[i] != a[0]:
            idx = i
            answer.append((1, i+1))
    if idx == -1:
        print("NO")
        continue
    print("YES")
    for i in range(1, n):
        if a[i] == a[0]:
            answer.append((i+1, idx+1))
    for u, v in answer:
        print(u, v)