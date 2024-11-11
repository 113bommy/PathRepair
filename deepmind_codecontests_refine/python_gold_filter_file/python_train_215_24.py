
def find(fin,s):
    if(s<fin[0]):
        return -1
    if(s>fin[-1]):
        return len(fin)-1
    i=0
    while(s>fin[i]):
        i+=1
    return i-1
    
n,s=input().split()
n=int(n)
s=int(s)
array=input().split()
fin=[]
for i in array:
    fin.append(int(i))
fin.sort()
#print(fin)
if(s not in fin):
    mids=n//2
    ind=find(fin,s)
    if(ind<mids):
        ind=ind+1
    #print("before",ind)
    if(ind<mids):
        sums=0
        while(ind<=mids):
            #print("if",ind)
            sums+=abs((fin[ind]-s))
            ind+=1
    else:
        sums=0
        while(ind>=mids):
            #print("else",ind)
            sums+=abs((fin[ind]-s))
            #print(sums)
            ind-=1
else:

    ind=fin.index(s)+1
    remele=ind-((n+1)//2)
    #print(ind,remele)
    if(remele>0):
        sums=0
        i=1
        while(i<=remele):
            sums+=(s-fin[ind-i-1])
            i+=1
    else:
        remele=-1*remele
        sums=0
        i=1
        while(i<=remele):
            sums+=(fin[ind+i-1]-s)
            i+=1
print(sums)
