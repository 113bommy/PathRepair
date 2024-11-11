inp = input().split()
n = int(inp[0])
h = int(inp[1])
dor = 0
hei = list(input().split())
for i in range(n):
  if int(hei[i]) > h:
    dor+=2
  else:
    dor+=1
print(dor)      