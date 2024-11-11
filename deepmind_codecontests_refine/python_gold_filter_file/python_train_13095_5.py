n=int(input())
s=input()
j=1
for i in range(n-1):
  if s[i]!=s[i+1]:
    j+=1
print(j)

  