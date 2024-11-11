s=list(map(int,input()))
t=list(map(int,input()))
dis=0
for i in range(len(s)):
    dis+=abs(s[i]-t[i])
if dis%2!=0:
    print('impossible')
else:
    dis=(dis//2)
    for i in range(len(s)):
        if s[i]!=t[i] and dis:
            s[i]=t[i]
            dis-=1
        print(s[i],end='')