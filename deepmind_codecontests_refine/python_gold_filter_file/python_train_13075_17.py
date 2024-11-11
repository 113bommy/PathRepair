n,m=map(int,input().split())
s=input()
t=input()
max=-1
matches=0
list1=[]
list2=[]
for i in range(m-n+1):
    list1.clear()
    matches=0
    for j in range(0,n,1):
        if s[j]==t[i+j]:
            matches+=1
        else:
            list1.append(j+1)
    if matches>max:
        list2.clear()
        max=matches
        list2=list1.copy()

print(len(list2))
print(' '.join(str(x) for x in list2))