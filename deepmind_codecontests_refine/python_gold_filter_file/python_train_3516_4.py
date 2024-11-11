N = int(input())
A = list(map(int, input().split()))

ans = 0
for a in A:
    ans ^= a
#print(ans)
for a in A:
  	print(ans^a)