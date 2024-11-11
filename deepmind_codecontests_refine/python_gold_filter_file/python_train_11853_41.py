H, W = map(int, input().split())
print("#" * (W + 2))
for i in range(H):
  s = input()
  print("#" + s + "#")
print("#" * (W + 2))