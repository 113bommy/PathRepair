a,b,c,d=input().split()
def tri(q,w,e):
    if(q<w+e):
        
        if(w<q+e):
            if(e<q+w):
                k=1
                return k
            elif(e==q+w):
                k=2
                return k
            else:
                return 0
        else:
            if(w==q+e):
                if(e<q+w):
                 k=2
                 return k
            elif(e==q+w):
                 k=2
                 return k
            else:
                return 0
    elif(q==w+e):
        if(w<q+e):
            if(e<q+w):
                k=2
                return k
            elif(e==q+w):
                k=2
                return k
            else:
                return 0
        else:
            if(w==q+e):
                if(e<q+w):
                 k=2
                 return k
            elif(e==q+w):
                 k=2
                 return k
            else:
                return 0
    else:
        return 0
           
z=[]
a=int(a)
b=int(b)
c=int(c)
d=int(d)
l=tri(a,b,c)
z.append(l)
l=tri(a,b,d)
z.append(l)
l=tri(a,c,d)
z.append(l)
l=tri(c,b,d)
z.append(l)
if(1 in z):
    print("TRIANGLE")
elif(2 in z):
    print("SEGMENT")
else:
    print("IMPOSSIBLE")




    

