s=input()
l=len(s)
k=int(input())
x=set()
for i in range(1,min(l,k)+1):
    for j in range(l-i+1):
        x.add(s[j:j+i])
x=sorted(list(x))
print(x[k-1])
