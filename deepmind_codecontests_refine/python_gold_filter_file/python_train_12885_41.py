s=input()
t=input()
con=0
for i in range(len(s)):
  if s[i]!=t[i]:
    con+=1
print(con)