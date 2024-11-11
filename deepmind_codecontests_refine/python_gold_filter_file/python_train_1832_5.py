a = input()
l = len(a)
k=0
if l%2==1:
    for i in range(l//2+1):
        if a[i]!=a[l-1-i]:
            k+=1
        if k>1:
            print("NO")
            break
    if k==0:
        print("YES")
else:
    for i in range(l//2):
        if a[i]!=a[l-1-i]:
            k+=1
        if k>1:
            print("NO")
            break
    if k==0:
        print("NO")
if k==1:
    print("YES")