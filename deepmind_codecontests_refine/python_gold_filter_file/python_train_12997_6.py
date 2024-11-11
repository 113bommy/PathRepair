import heapq

N = int(input())
A = list(map(int, input().split()))
 
L = A[:N]
heapq.heapify(L) 

sum_L = [0] * (N+1)
sum_L[0] = sum(L)

for i in range(N):
    min_L = heapq.heappushpop(L, A[N+i])
    sum_L[i+1] = sum_L[i] + A[N+i] - min_L
    #print(L, i, A[N+i], min_L, sum_L)

R = A[N*2:]
rev_R = list(map(lambda x: x*(-1), R))
heapq.heapify(rev_R) 

sum_R = [0] * (N+1)
sum_R[N] = sum(R)

for i in range(N-1, -1, -1):
    max_R = heapq.heappushpop( rev_R, A[N+i]*(-1) ) * (-1)
    sum_R[i] = sum_R[i+1] + A[N+i] - max_R
    # print(rev_R, i, A[N+i], max_R, sum_R)

ans = -10**14

for i in range(N+1):
    ans = max(ans, sum_L[i] - sum_R[i])

print(ans)