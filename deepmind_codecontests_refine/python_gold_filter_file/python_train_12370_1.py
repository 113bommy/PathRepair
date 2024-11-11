N = int(input())
a = ""
if N ==0:
  a =0
while N !=0:
  if N%2 != 0:
    a = "1" + a
  else:
    a = "0" + a
  N = - (N//2)
print(a)