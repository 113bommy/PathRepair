from fractions import gcd

N, M = map(int, input().split())
A = [int(i) // 2 for i in input().split()]  

A_lcm = 1
for i in range(N):
    A_lcm *= A[i] // gcd(A_lcm, A[i])
    
for i in A:
    if A_lcm // i % 2 == 0:
        print(0)
        exit()

print((M // A_lcm + 1) // 2)