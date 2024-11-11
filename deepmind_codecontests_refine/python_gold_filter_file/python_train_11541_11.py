a,b,c=map(int,input().split())
flag="NO"
for i in range(1,100):
  if a*i%b==c:
    flag="YES"
    break
print(flag)