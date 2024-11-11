s=input()
x=int(input())
ans=""
for i in range(0,len(s),x):
  ans+=s[i]
print(ans)