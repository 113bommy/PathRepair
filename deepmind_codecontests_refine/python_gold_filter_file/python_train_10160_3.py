n,m,k,r=map(int,input().split())
dic={}
li=["Carrots","Kiwis","Grapes"]
li1=[]
for i in range(k):
    a,b=map(int,input().split())
    li1.append((a,b))
li1.sort()
#print(li1)





for d in range(r):
    t=0
    cnt=0
    v,w=map(int,input().split())
    for j in li1:
        #print(j,cnt)
        #print("v=",v,"w=",w)
        #print("j[0]=",int(j[0]),"j[1]=",int(j[1]))
        if int(j[0])==v and int(j[1])==w:
            #print(j[0],j[1])
            t=2
            print("Waste")
            break
        elif int(j[0])>v:
            
            break
        elif int(j[0])==v and int(j[1])>w:
            break
        cnt+=1
        #print(cnt)
    #print("cnt=",cnt)
    if t!=2:
        o=(v-1)*m+w-cnt-1
        #print("0=",o)
        print(li[o%3])





