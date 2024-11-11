n=int(input())
n1=input()
lst=[]
s=n1[:n]+'z'
k=0
m=0
n=0
if(s.count('x')==len(s)):
    print(s.count('x')-2)
else:
    for i in s:
        if(i=='x'):
            k=k+1
            continue
        lst.append(k)
        k=0
    for j in lst:
        if(j>=2):
            z=j-2
            m=m+z
    print(m)

