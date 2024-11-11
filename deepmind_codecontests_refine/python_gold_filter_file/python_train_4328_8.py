n=int(input())
l_lst=[]
r_lst=[]
for i in range(n):
    l,r=list(map(int,input().split()))
    l_lst.append(l)
    r_lst.append(r)
left=sum(l_lst)
right=sum(r_lst)
c_beauty=abs(left-right)
index=0
for i in range(n):
    lol=abs((left-l_lst[i]+r_lst[i])-(right+l_lst[i]-r_lst[i]))
    if lol >c_beauty:
        c_beauty=lol
        index=i+1
print(index)