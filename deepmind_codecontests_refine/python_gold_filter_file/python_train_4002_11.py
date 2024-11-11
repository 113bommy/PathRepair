s=input()
f1,f2,f3,f4=0,0,0,0
for i in range(len(s)):
    if 0<=ord(s[i])-ord('a')<26:
        f1=1
    if len(s)>=5:
        f2=1
    if 0<=ord(s[i])-ord('A')<26:
        f3=1
    if 0<=ord(s[i])-ord('0')<10:
        f4=1
if f1==1 and f2==1 and f3==1 and f4==1:
    print("Correct")
else:
    print("Too weak")
