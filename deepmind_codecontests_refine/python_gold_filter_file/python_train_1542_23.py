N = int(input())
arr = [0] + list(map(int, input().split(' '))) #ずらしておく。
for i in range(N//2, 0, -1):
  arr[i] = sum(arr[i::i]) % 2
ans = [i for i, j in enumerate(arr) if j == 1]
print(len(ans))
print(*ans)
