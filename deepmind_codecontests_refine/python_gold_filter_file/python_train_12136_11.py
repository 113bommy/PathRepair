n = int(input())
p=n
liste = []
s=input()
liste1=list(s)
for i in range(n):
    p+=1
    if p%2==0:
        liste.append(liste1.pop(0))
    if p%2==1:
        liste.insert(0,liste1.pop(0))

print(*liste,sep="")
