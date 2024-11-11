mx=[]
a=input()+'A'
jump=0
for i in range(len(a)):
    if a[i] in ['A','E','I','O','U','Y']:
        mx.append(jump+1)
        jump=0
    else:
        jump+=1
mx.append(jump)

print(max(mx))
