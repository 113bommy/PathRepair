n=int(input())
s=input()
t=input()
for i in range(n,2*n+1):
  a=s[:n]+t[2*n-i:]
  if a[-n:]==t:exit(print(i))