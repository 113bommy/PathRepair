N,Q = map(int, input().split())
S = input()
C = [tuple(map(str, input().split())) for _ in range(Q)]
C = C[::-1]

left = -1
right = N

for (t,d) in C:
  if ('L' == d):
    if (S[left+1] == t):
      left += 1
      if (N-1 <= left):
        print(0)
        exit()
    if (right < N):
      if (S[right] == t):
        right += 1
        if (N < right):
          right = N
  else:
    if (S[right-1] == t):
      right -= 1
      if (right <= 0):
        print(0)
        exit()
    if (-1 < left):
      if (S[left] == t):
        left -= 1
        if (left < -1):
          left = -1

print(right - left - 1)
