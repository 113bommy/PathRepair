n,m=[int(i) for i in input().split()]
s=str(input())
t=str(input())
p=s.find('*')
z=n-p
if p==-1 and s!=t:
        print("NO")
elif s==t:
        print("YES")
else:
        #print(t[:p],s[:p],t[::-1][:n-p-1],s[p+1:],p)
        if t[:p]==s[:p] and t[::-1][:n-p-1][::-1]==s[p+1:] and n<=m+1:
                print('YES')
        else:
                print('NO')
