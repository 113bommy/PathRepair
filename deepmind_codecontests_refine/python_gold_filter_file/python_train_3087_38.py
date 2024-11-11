n = int(input())
s=input()
s=list(s)
vow = ['a','e','i','o','u','y']
i = 0
while i<n-1:
    if s[i] in vow and s[i+1] in vow:
        s.pop(i+1)
        n-=1
    else:
        i+=1
#print(s)
for i in s:
    print (i,end='')