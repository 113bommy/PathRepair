n,m=[int(x) for x in input().split(" ")]
poland=[]
enemy=[]
repetidas=0
for i in range(n):
    poland.append(input())
for i in range(m):
    palabra=input()
    if palabra in poland:
        repetidas+=1
if (repetidas%2==1):
    if (n>=m):
        print("YES")
    else:
        print("NO")
else:
    if(n>m):
        print("YES")
    else:
        print("NO")