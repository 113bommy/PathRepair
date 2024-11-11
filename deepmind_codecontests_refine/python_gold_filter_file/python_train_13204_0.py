a=input()
l=len(a)
b=l*(l-1)//2+1
for i in range(97,123):
    c=a.count(chr(i))
    d=c*(c-1)//2
    b-=d
print(b)