n = int(input())
li=[]
for i in range(n):
    a ,b ,c = map(int,input().split())
    li.append([a,b,c,i+1])
li.sort()
i=0
l=len(li)
a=[]
while i<l:
#    print(li[i][:2],li[i+1][:2])
    if i<l-1 and li[i][:2]==li[i+1][:2]:
        print(li[i][3],li[i+1][3])
        i+=2
    else:
        a.append(li[i]) 
        i+=1
li=list(a)
l=len(li)
i=0
a=[]
#print(li)
while i<l:
    if i<l-1 and li[i][0]==li[i+1][0]:
        print(li[i][3],li[i+1][3])
        i+=2
    else:
        a.append(li[i]) 
        i+=1      
li=list(a)
l=len(li)
i=0
#print(li)
while i<l-1:
    print(li[i][3],li[i+1][3])
    i+=2