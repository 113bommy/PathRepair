a=input()
b=list(a)
c=len(b)
n=0
for i in range(c):
    if b[i]<"a":
        n=n+1
d="".join(b)
if 2*n>c:
    e=d.upper()
else:
    e=d.lower()
print(e)
