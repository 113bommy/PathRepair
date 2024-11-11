n = int(input())
arr = list(map(int, input().split()))

c = 0
for i, v in enumerate(arr):
  if i+1!=v:
    c += 1
print("YES" if c==2 or c==0 else "NO")
