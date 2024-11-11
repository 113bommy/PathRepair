n = int(input())
a = list(map(int, input().split()))
box = [0] * n
ans = []

for i in range(n-1, -1, -1):
    ms = sum(box[i::i+1])
    if ms % 2 != a[i]:
        box[i] = 1
        ans.append(i+1)

print(len(ans))
print(*ans)
