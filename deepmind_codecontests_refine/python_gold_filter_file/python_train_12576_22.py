#k,a,b=map(int,input().split())
n=int(input())
s=[input() for i in range(n)]
fin_a=0
ini_b=0
ab=0
for i in s:
    if i[0]=='B' and i[-1]=='A':
        ab+=1
    elif i[0]=='B':
        ini_b+=1
    elif i[-1]=='A':
        fin_a+=1

s='+'.join(s)
ans=s.count('AB')
print(ans+min(fin_a+ab,ini_b+ab) if not (fin_a==0 and ini_b==0) else ans+max(ab-1,0))
