s=str(input())
s=s.lower()
s=s.replace(" ","")
v="aeiouy"
if s[-2] in v:
     print("YES")
else:
     print("NO")

