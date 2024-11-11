s=input()
s = ''.join(sorted(s)) 
s=s[::-1]
c=0
maxx=-1
st=s[0]
for i in range(1,len(s)):
    if s[i-1]==s[i]:
        c+=1
    elif maxx<c and s[i-1]>=st:
        st=s[i-1]
        maxx=c 
        c=0
if c+1==len(s):
    print(st*(c+1))
else:
    print(st*(maxx+1))