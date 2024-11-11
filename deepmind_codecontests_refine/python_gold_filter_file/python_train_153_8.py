import sys
c,n=0,0
for sr in sys.stdin:
    if(sr[0]=='+'):
        n+=1
    elif(sr[0]=='-'):
        n-=1
    else:
        i=sr.index(':')
        c+=((len(sr)-2-i)*n)
print(c)
        
