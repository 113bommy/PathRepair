s=input()
s+='A'
m=0
k=1
p=0
for i in s:
    if i in "AEIOUY":
        m=max(m,k-p)
        p=k
    k+=1
print(m)