N=int(input())
S=input()
cnt=0
for i in range(1000):
  con=0
  if i<10:
    a="00"+str(i)
  elif i<100:
    a="0"+str(i)
  else:
    a=str(i)
  for j in range(N):
    if S[j]==a[con]:
      con+=1
      if con==3:
        cnt+=1
        break
print(cnt)