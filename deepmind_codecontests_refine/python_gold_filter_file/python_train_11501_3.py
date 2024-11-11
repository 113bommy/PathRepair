m,s = map(int,input().split())
if s==0 and m>1:
  s = -1
ans = ""
ans1 = ""
s1 = s - 1
k = 0
while s>0:
  if s>=9:
    ans += "9"
    s -= 9
  else:
    ans += str(s)
    s -= s
t = 0
if len(ans)>0:
  t = 1 if len(ans)<m else 0 
  ans1 = str(int(ans)-t)
  k += t
if len(ans)>m or len(ans1)>m or s==-1:
  print("-1 -1")
else:
  if s1==-1 and m==1:
    print("0 0")
  else:
    ans = ans+(m-len(ans))*"0"
    ans1 = "1"*k+"0"*(m-len(ans1)-1)+ans1[::-1]
    print(ans1,ans)