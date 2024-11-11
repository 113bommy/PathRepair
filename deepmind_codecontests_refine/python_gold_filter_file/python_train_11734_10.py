def removeChar(s, c,counts) :
    s = list(s) 
    while counts : 
        s.remove(c) 
        counts -= 1
  
    s = '' . join(s) 
      
    return s 










lol=input()
n=int(lol.split(' ')[0])
k=int(lol.split(' ')[1])
#print (n,k)
s = input()

men = len(s)


liss ={}



lisu=[]

for i in list('abcdefghijklmnopqrstuvwxyz'):
    hehe=s.count(i)
    if hehe>k:
        liss[i]=k
        k=k-hehe
        break
    else :
        liss[i]=-1
        lisu.append(i)
        k=k-hehe


#print (liss)

for i in s:
    if i in liss.keys():
        if liss[i]>0:
            liss[i]-=1
            if liss[i] <=0 :
                liss.pop(i)
        elif liss[i]==0:
            print(i,end="")
            liss.pop(i)
    else :
        print(i,end="")


print()


