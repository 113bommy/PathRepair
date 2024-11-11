n=int(input())
def func(num):
    arr=[]
    for i in range(len(num)):
        arr.append(int(num[i]))
    if len(set(arr))==1:
        return 1 
    arr1=arr.copy() 
    arr.sort(reverse=True)
    if arr1==arr and len(set(arr1))==6:
        return 2 
    else:
        return 3 
        
    
        
tcount,pcount,gcount=0,0,0
t,p,g=[],[],[]
        
dict={}
for i in range(n):
    phone,name=input().split();phone=int(phone)
    taxi,pizza,girl=0,0,0
    while phone>0:
        phone-=1 
        x=input().split("-")
        num=""
        for item in x:
            num+=str(item)
        if func(num)==1:
            taxi+=1 
        elif func(num)==2:
            pizza+=1 
        elif func(num)==3:
            girl+=1 
    dict[name]=str(taxi)+str(pizza)+str(girl)
    if taxi>=tcount:
       
        if taxi>tcount:
            t=[]
            t.append(name)
        elif taxi==tcount:
            t.append(name)
        tcount=taxi
    if pizza>=pcount:
       
        if pizza>pcount:
            p=[]
            p.append(name)
        elif pizza==pcount:
            p.append(name)
        pcount=pizza
    if girl>=gcount:
        
        if girl>gcount:
            g=[]
            g.append(name)
        elif girl==gcount:
            g.append(name)
        gcount=girl

t=", ".join(t)
p=", ".join(p)
g=", ".join(g)

print("If you want to call a taxi, you should call: {}.".format(t))
print("If you want to order a pizza, you should call: {}.".format(p))
print("If you want to go to a cafe with a wonderful girl, you should call: {}.".format(g))

        
        