N = int(input())
A = list(map(int, input().split()))
B = [0] * (N+1)

for i in A:
    B[i] += 1
sum_original = sum([j*(j-1)//2 for j in B])
for k in range(N):
    print(sum_original - B[A[k]] + 1)