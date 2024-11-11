N = int(input())
A = [int(i) for i in input().split()]

nums = []
memo = [0] * N
for i in range(N - 1, -1, -1):
    if A[i] != sum(memo[i :: i + 1]) % 2:
        memo[i] = 1
        nums.append(i + 1)
        
print(sum(memo))
print(' '.join(map(str, nums)))