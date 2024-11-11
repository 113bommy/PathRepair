n=int(input())
a=0
b=0
c=0
d=0
for i in range(n):
  S=input()
  for i in range(len(S)-1):
    if S[i]=="A" and S[i+1]=="B":
      c=c+1
  if S[0]=="B":
    b=b+1
  if S[-1]=="A":
    a=a+1
  if S[0]=="B" and S[-1]=="A":
    d=d+1
if a==b and b==d and a!=0:
  print(c+min(a,b)-1)
else:
  print(c+min(a,b))