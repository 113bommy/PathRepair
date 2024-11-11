s=input().split("|")
s2= input()
for i in s2:
   if len(s[0])>len(s[1]):
      s[1]+=i
   else:
      s[0]+=i
if len(s[1])!=len(s[0]):
   print("Impossible")
else:
   print(s[0]+"|"+s[1])