n=int(input())
s=input()
d=list(map(int,'0'*(n+1)))
for i in range(n):
  d[i+1]=1+d[i] if s[i]=='I'else -1+d[i]
print(max(d))