l=list(map(int,input().split()))
l1=list(input().split())
l2=list(input().split())
q=int(input())
li=[]
while q>0:
    n=int(input())
    li.append(n)
    q=q-1
for i in li:
    a=i%l[0]
    b=i%l[1]
    s=l1[a-1]+l2[b-1]
    print(s)
    
    