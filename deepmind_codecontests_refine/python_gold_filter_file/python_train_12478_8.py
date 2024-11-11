n=int(input())
s=input()
t=input()
while True:
  if s==t:
    break
  s=s[1:]
  t=t[:-1]
  n+=1
print(n)
