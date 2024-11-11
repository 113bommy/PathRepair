n=int(input())
s=input()
l="asdfghjklzxcvbnmpoiuytrewq"
t=True
for i in l:
    if(i not in s and  i.upper() not in s):
        print("NO")
        t=False
        break
    else:
        continue
if(t==True):
    print("YES")
        
