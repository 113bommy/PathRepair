l = ['A', 'E', 'I', 'O', 'U', 'Y','a','e','i','o','u','y']
x = input()
i = x.index('?')-1
while x[i]==' ':
    i-=1
    if x[i]!=' ':
        break
    
if x[i] in l:
    print("YES")
else:
    print("NO")