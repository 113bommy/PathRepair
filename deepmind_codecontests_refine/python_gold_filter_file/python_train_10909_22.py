n=int(input())
s=input()

nsl=['{:03}'.format(i) for i in range(1000)]

res=0
for ns in nsl:
  idx=0
  for char in s:
    if char == ns[idx]:
      idx+=1
      if idx == 3:
        res+=1
        break
print(res)
