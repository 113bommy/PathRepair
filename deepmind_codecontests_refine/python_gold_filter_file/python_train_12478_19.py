n=int(input())
s=input()
t=input()
l=2*n
for i in range(n):
  if s[i:]==t[:n-i]:
    l=n+i
    break
print(min(n*2,l))