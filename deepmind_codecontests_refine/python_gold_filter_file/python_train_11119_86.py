d = [int(input()) for _ in range(5)]
k = int(input())
print('Yay!' if d[-1] - d[0] <= k else ':(')
