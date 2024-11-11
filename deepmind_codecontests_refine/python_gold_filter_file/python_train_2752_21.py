n=int(input())
a=[int(x) for x in input().split()]
police=0;crimes=0
for i in a:
    if i > 0:
        police+=i
    elif police>=1:
        police-=1
    else:
        crimes+=1
print(crimes)