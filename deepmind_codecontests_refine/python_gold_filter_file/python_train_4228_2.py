def per(l):
    for i in range(1,len(l)+1):
        if i not in l:
            return False
    return True
def dm(l1,l2):
    ans=0
    for i in range(len(l1)):
        if l1[i]!=l2[i]:
            ans+=1
    return ans
n=int(input())
#n,k=(int(n),int(k))
a=list(map(int,input().strip().split(' ')))
b=list(map(int,input().strip().split(' ')))
list1=[]
for i in range(n):
    if a[i]!=b[i]:
        list1.append(i)
list2=[]
for i in range(1,n+1):
    if i not in a:
        list2.append(i)
for j in range(len(list2)):
    for i in range(len(list1)):
        d=a[:]
        d[list1[i]]=list2[j]
        #print(d)
        if d!=b and dm(d,b)==1 and per(d):
            print(*d)
            exit()