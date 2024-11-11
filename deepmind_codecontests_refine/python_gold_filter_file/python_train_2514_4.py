n = int(input())
num = input()
f = [0] + list(map(int, input().split()))
right = 0
left = 0
for i in range(n):
    if f[int(num[i])] > int(num[i]):
        right = left = i
        while f[int(num[right])] >= int(num[right]):
            right += 1
            if right >= n:
                break
        break
newnum = list(map(int, list(num)))
for i in range(left, right):
    newnum[i] = f[newnum[i]]
print(''.join(list(map(str, newnum))))
