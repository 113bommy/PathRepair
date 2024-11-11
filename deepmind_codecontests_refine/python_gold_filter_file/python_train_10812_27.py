s=input()
k=int(input())
l=list(s)

for i in range(len(s)):
  f=(-ord(s[i])+ord("z")+1)%26
  if f<=k:
    l[i]="a"
    k-=f

k=k%26
a=ord(l[-1])+k 
if a> ord("z"):a-=26
l[-1]=chr(a)
print("".join(l))