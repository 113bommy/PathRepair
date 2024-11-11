z=list(map(int,input().split()))
x=[]
for i in range(z[0]):
    t=list(map(int,input().split()))
    x.append(str(t[0]))
a="".join(x)
o=[]
c=-1
for u in range(z[1]):
    c=c+1
    qr=-1
    yu=0
    v=[]
    for y in range(c,len(a),z[1]):
        qr=qr+1
        v.append(str(a[y])+"s"+str(qr))
        yu=yu+z[1]
        if yu==z[1]:
            o.append(v) 
                 
        
ap=[]
for re in o:
    re.sort()
    aq=re[-1]
    for wr in re:
        if wr[0] ==aq[0]:
            ap.append(wr)
    
op=[]
for i in ap:
    op.append(i[1:2+len(str(z[0]))])
ui=[]
for i in op:
    if i not in ui:
        ui.append(i)
print(len(ui))




