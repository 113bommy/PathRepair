l=int(input())
p=input()
n=len(p)
a=p[n-1]
i=n-3
count=1
while i>=0:
    if p[i]==a:
        count=count+1
    else:
        break
    i=i-2
print(l-count)