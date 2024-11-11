N = int(input())
A = list(map(int, input().split()))

not_in = [0 for i in range(N+1)]
not_in[0] = A[0]
for i in range(1, N+1):
  not_in[i] = not_in[i-1] * 2 + A[i]

if not_in[N] > 2 ** N:
  print(-1)
else:
  in_num = 0
  up = A[N]
  for i in range(N-1,-1,-1):
    in_temp = min(2 ** i - not_in[i], up)
    in_num += in_temp
    up = in_temp + A[i]
  print( in_num + sum(A) )
