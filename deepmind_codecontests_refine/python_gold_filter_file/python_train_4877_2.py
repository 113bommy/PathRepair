N = int(input())
A = list(map(int,input().split()))
num = [0 for i in range(200000)]
for i in range(N):
    num[A[i]-1] += 1
    num[A[i]] += 1
    num[A[i]+1] += 1
print(str(max(num)))