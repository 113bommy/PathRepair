n=int(input())
arr=[]
f=0
for i in range(1,45000):
    arr.append((i*(i+1))//2)
for el in arr:
    if (n-el) in arr:
        f=1
        break
if(f==1):
    print("YES")
else:
    print("NO")

        
                
