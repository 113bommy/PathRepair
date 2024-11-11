n=input()
k=n.find(" ")
l=k
k=int(n[:l])
n=n[l+1:]
l=int(n)
n=k
m=l
s=input()
t=input()
list1=[]
list2=[]
while s.count(" "):
        p=s.find(" ")
        q=p
        p=s[:p]
        list1.append(p)
        s=s[q+1:]
list1.append(s)
while t.count(" "):
    p = t.find(" ")
    q = p
    p = t[:p]
    list2.append(p)
    t = t[q + 1:]
list2.append(t)
q=int(input())
i=0
while i<q:
    y=int(input())
    print(list1[(y-1)%n],end="")
    print(list2[(y-1)%m])
    i+=1
