l=list(map(int,input().split()))
l.sort()
dic={}
s=set(l)
u=0
for i in s:
    if l.count(i)>=4:
        u=1
if u==0:
    print("Alien")
    exit(0)
for i in l:
    if dic.get(i):
        dic[i]+=1 
    else:
        dic[i]=1
key=list(dic.keys())
#print(key)
if len(key)>3:
    print("Alien")
    exit(0)
elif len(key)==3:
    print("Bear")
elif len(key)==2:
    flag=0
    
    for k,v in dic.items():
        if v==5:
    #        print("Bear")
     #       exit(0)
            flag=1
    if flag:
        print("Bear")
    else:
        print("Elephant")
else:
    print("Elephant")


    