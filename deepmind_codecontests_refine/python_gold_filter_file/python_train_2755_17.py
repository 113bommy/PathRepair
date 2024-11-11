n=int(input())
list1=list(map(int,input().split()))
list2=[]
for i in range(n-1):
    list2.append(abs(list1[i]-list1[i+1]))
x=max(list2)
m=100000
for i in range(len(list2)-1):
    s=list2[i]+list2[i+1]
    if(s<m):
        m=s
print(max(x,m))