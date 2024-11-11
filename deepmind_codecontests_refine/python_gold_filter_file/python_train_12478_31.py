n=int(input())
s=input()
t=input()
if s==t:
  print(n)
  exit()
for i in range(n):
  if s[i+1:] == t[:-i-1]:
    print(n+i+1)
    break