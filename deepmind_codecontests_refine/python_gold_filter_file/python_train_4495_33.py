m=input()
str=(m.lower())
l=['a','o','y','e','u','i']
n=[]
for x in str:
    if x not in l:
        n.append('.')
        n.append(x)
print(''.join(n))