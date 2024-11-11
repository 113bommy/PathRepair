N = int(input())
A = list(map(int, input().split()))
A.sort()
print(sum(A[::-2]) - sum(A[-2::-2]))