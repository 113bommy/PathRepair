n=int(input())
s=input()
diff=(s.count('x')-s.count('X'))//2
print(abs(diff))
s=list(s)
for i in range(n):
    if diff>0 and s[i]=='x' :
        s[i]='X'
        diff-=1
    elif diff<0 and s[i]=='X':
        s[i]='x'
        diff+=1
print(''.join(s))