n=int(input())
st=list(input())
need=0
i=0
while i<len(st):
    if st[i]=='x':
        c=0
        c+=1
        j=i+1
        while j<len(st):
            if st[j]!='x':
                break
            c+=1
            j+=1
        if c>2:    
           need+=c-2
        i=j
    i+=1
print(need)               

