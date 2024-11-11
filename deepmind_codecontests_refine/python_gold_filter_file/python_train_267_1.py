c, v0, v1, a , l =map(int,input().split())
e=v0
f=1
if c<=v0:
    f=1
else:
    while(e<c):
        v0=min(v1,v0+a)



        f+=1
        e=e-l+v0
        
        #print(e-l+v0)
    
print(f)    
    