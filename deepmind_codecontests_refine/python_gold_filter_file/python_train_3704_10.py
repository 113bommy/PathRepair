s=input()
if(s[0]!='a'):
    print("NO")
    exit()
l=[True]
for _ in range(25):
    l.append(False)
for i in range(1,len(s)):
    l[ord(s[i])-ord('a')]=True
    if(s[i]!='a' and l[ord(s[i])-ord('a')-1]==False):
        print("NO")
        exit()
print("YES")
