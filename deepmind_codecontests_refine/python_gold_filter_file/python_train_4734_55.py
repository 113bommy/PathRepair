m=['a','e','i','o','u','y','A','E','I','O','U','Y']
x=input()
i=x.index('?')-1
while x[i]==' ':
            i=i-1
            if x[i]!=' ':
                        break
if x[i] in m:
            print("YES")
else:
            print("NO")