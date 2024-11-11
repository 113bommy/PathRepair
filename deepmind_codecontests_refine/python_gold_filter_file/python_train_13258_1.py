arr=list(map(int,input().strip().split()))
s=arr[0]
a=[]
flag=0
for i in range(arr[1]):
    l=list(map(int,input().strip().split()))
    a.append((l[0],l[1]))
a.sort()
for i in a:
    if s>i[0]:
        s=s+i[1]
    else:
        print("NO")
        flag=1
        break
if flag==0:
    print("YES")
