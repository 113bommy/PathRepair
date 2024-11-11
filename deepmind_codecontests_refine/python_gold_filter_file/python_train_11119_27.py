a = [int(input()) for i in range(5)]
k = int(input())
print('Yay!' if a[-1] - a[0] <= k else ':(')
