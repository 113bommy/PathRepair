N=int(input())
s=input()
t=input()
for i in range(len(s),-1,-1):
  if s[-i:]==t[:i]:
    break
print(len(s+t[i:]))