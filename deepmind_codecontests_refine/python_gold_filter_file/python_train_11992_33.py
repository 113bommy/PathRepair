n=int(input(""))
s=input("")
if(len(s)==n):
    l=s
l=list(s)
flag=0
for i in range(0,len(s)):
    if(s[i]=="o" or "n" or "e" or "z" or "r"):
        flag=0
    else:
        flag=1
if(flag==0):
    l.sort()
    d={}
    a=s.count("o",0,len(s))
    b=s.count("n",0,len(s))
    c=s.count("e",0,len(s))
    h=s.count("z",0,len(s))
    e=s.count("r",0,len(s))
    d["o"]=a
    d["n"]=b
    d["e"]=c
    d["z"]=h
    d["r"]=e
    max=0
    q=[a,b,c]
    q.sort()
    s=""
    if(q[0]>=1 and q[1]>=1 and q[2]>=1):
        for i in range(0,q[0]):
            s=s+"1"
        q[1]=q[1]-q[0]
        q[2]=q[2]-q[0]
    q.remove(q[0])
    q.append(h)
    q.append(e)
    q.sort()
    if(q[0]>=1 and q[1]>=1 and q[2]>=1 and q[3]>=1):
        for i in range(0,q[0]):
            s=s+"0"
    for i in s:
        print(i,end=" ")

    




    
    
    
    
