h,w = list(map(int, input().split()))
print("#"*(w+2))
for i in range(h):
  print("#", input(), "#", sep="")
print("#"*(w+2))