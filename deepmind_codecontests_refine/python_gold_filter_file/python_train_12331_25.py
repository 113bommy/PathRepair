a=map(int, input().split(" "))
b=map(int, input().split(" "))
n=int(input())
cups=0
med=0
for i in a:
    cups+=i
for j in b:
    med+=j

if cups%5==0:
    cupsused=n-(cups//5)
else:
    cupsused=n-(cups//5)-1

if med%10==0:
    medsuse=cupsused-(med//10)
else:
    medsuse=cupsused-(med//10)-1

if medsuse>=0:
    print("YES")
else:
    print("NO")
