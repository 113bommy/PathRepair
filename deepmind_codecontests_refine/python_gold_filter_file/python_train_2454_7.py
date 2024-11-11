a=int(input())
b=int(input())
c=int(input())
cnt=0
while (True):
  a-=1;b-=2;c-=4
  if a>=0 and b>=0 and c>=0:
    cnt+=7
  else:
    break
print(cnt)    

