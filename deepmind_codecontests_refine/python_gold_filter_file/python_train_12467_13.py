*l,=map(list,zip(input(),input()))
a=0
for i in range(1,len(l)):
    if l[i-1]==['0','0']:
        if l[i]==['0','0']:
            a+=1
            l[i]=['0','X']
        elif l[i]==['0','X'] or l[i]==['X','0']:
            a+=1
            l[i]=['X','X']
    elif l[i-1]==['0','X'] or l[i-1]==['X','0']:
        if l[i]==['0','0']:
            a+=1
            l[i]=['X','X']
print(a)