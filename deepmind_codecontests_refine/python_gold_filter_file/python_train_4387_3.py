n=input()
count=0
p=[x for x in input().split()]
for i in p:
    if i[0]==n[0] or i[1]==n[1]:
        print("YES")
        break
    else:
        count+=1
if count==len(p):
    print("NO")