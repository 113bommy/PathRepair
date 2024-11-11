N = int(input())
S = [int(x) for x in list(input())]
total = 0
for a in range(1000):
  tmp = [a//100,a//10%10,a%10]
  i = 0
  for x in range(N):
    if tmp[i] == S[x]:
      i+=1
    if i==3:
      total+=1
      break
print(total)