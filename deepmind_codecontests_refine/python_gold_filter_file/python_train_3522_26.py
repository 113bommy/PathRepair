N = int(input())
CSF = [list(map(int,input().split())) for _ in range(N-1)]

for i in range(N):
  t = 0
  for j in range(i,N-1):
    if(t < CSF[j][1]):
      t = CSF[j][1]
    elif(t%CSF[j][2] == 0):
      pass
    else:
      t += CSF[j][2]-t%CSF[j][2]
    t += CSF[j][0]
  print(t)