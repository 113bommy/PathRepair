s=input()
k=int(input())
a2n = lambda c: ord(c) - ord('a') + 1
n2a = lambda c: chr(c+64).lower()
ls=list(s)
i=0
while k>0 and i<len(ls):
  a=(1-a2n(ls[i]))%26
  if k>=a:
    ls[i]='a'
    k-=a
  i+=1
if k>0:
  ls[-1]=n2a(a2n(ls[-1])+k%26)
print(''.join(ls))