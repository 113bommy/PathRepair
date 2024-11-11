n = int(input())
tar = n//4
ls = ('A','G','T','C')
st = list(input())
count = [0,0,0,0]
j=0
for i in range (0,n):
    if st[i]=='A': count[0]+=1 
    if st[i]=='G': count[1]+=1 
    if st[i]=='T': count[2]+=1
    if st[i]=='C': count[3]+=1
#print (count[0],count[1],count[2],count[3])
if n%4: print("===")
elif  count[0]>(n//4) or count[1]>(n//4) or count[2]>(n//4) or count[3]>(n//4): print("===")
else:
    for i in range (0,n):
        if st[i]=='?':
             while(count[j]==n//4): j+=1 
             st[i]=ls[j]
             count[j]+=1
    ans = "".join(map(str,st))
    print (ans)
