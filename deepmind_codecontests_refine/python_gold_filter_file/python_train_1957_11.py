n=int(input())
s = list(input())
for l in s:
  m = ((ord(l)-65)+n)%26+65
  j = chr(m)
  print(j,end="",sep="")