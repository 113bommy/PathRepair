a = int(input())

N = [1,2,3,4,5,6,7,8,9]

for x in range(a):
  tmp = N[x]
  if tmp%10 != 0:
    N.append(tmp*10+tmp%10-1)
  N.append(tmp*10+tmp%10)
  if tmp%10 != 9:
    N.append(tmp*10+tmp%10+1)
print(N[a-1])