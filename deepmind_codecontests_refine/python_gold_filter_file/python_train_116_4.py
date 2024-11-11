n=int(input())
s=input();flag=True
for i in range(n-1):
  if s[i]<=s[i+1]:continue
  else:print("YES");print(i+1,i+2);flag=False;break
if flag:print("NO")

