p=False
n=int(input())
s=''
for i in range(n):
    n=input()
    if not p and 'OO' in n:
        n=n.replace('OO','++',1)
        p=True
    s+=n+'\n'
    #print(s)
    
if p:
    print("YES")
    print(s[:-1])
else:
    print("NO")
