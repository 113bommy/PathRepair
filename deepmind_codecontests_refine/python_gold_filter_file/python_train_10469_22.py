def min(*a):
    min=a[0]
    for i in a:
        if(i<min):
            min=i
    return min
def clock(a,b):
    if(a<b):
        a,b=b,a
    return min((ord(b)-ord('a'))+(ord('z')-ord(a))+1,ord(a)-ord(b))
if(__name__=='__main__'):
    s=input()
    p='a'
    sum=0
    for i in s:
        #print(clock(i,p))
        sum=sum+(clock(i,p))
        p=i
    print(sum)
