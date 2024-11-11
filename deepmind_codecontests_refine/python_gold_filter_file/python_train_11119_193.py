A = [int(input()) for _ in range(5)]
k = int(input())

print('Yay!' if A[4] - A[0] <= k else ':(')