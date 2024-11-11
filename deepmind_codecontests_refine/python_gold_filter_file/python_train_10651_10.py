n=int(input())
names=[]
arr=[]
max1=-1
max1i=0
max2=-1
max2i=0
max3=-1
max3i=0
for i in range(n):
    a,b=input().split()
    names.append(b)
    arr.append([0,0,0])
    for j in range(int(a)):
        x=list(''.join(input().split('-')))
        if len(set(x))==1:
            arr[i][0]+=1
        elif x==sorted(x,reverse=True) and len(set(x))==len(x):
            arr[i][1]+=1
        else:
            arr[i][2]+=1
for i in range(n):
    if arr[i][0]>max1:
        max1=arr[i][0]
        max1i=names[i]
    if arr[i][1]>max2:
        max2=arr[i][1]
        max2i=names[i]
    if arr[i][2]>max3:
        max3=arr[i][2]
        max3i=names[i]
flag1=False
flag2=False
flag3=False
for i in range(n):
    if arr[i][0]==max1:
        if flag1:
            max1i+=", "+names[i]
        else:
            flag1=True
    if arr[i][1]==max2:
        if flag2:
            max2i+=", "+names[i]
        else:
            flag2=True
    if arr[i][2]==max3:
        if flag3:
            max3i+=", "+names[i]
        else:
            flag3=True
print("If you want to call a taxi, you should call:",max1i,end='.\n')
print("If you want to order a pizza, you should call:",max2i,end='.\n')
print( "If you want to go to a cafe with a wonderful girl, you should call:",max3i,end='.\n')
