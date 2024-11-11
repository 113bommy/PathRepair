n=int(input())
s=input()
t=input()

for i in range(n+1):
  if s[i:]==t[:n-i]:
    print(n+i)
    exit()