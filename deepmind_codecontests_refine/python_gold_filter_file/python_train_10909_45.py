n=input()
s=input()

cnt=0
for i in range(0,1000):
  pos=0
  t="{0:03d}".format(i)
  for j in range(int(n)):
    if s[j] == t[pos]:
      pos+=1
    if pos == 3:
      cnt+=1
      break

print(cnt)