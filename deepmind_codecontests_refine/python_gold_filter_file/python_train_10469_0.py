def cnt(a,b):
    x=abs(ord(a)-ord(b))
    return(min(x,26-x))
a='a'+input()
val=0
for i in range(len(a)-1):
    val+=cnt(a[i],a[i+1])
print(val)