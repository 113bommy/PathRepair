n=int(input())
string=input()
sub={}
i=0
while(i<=n-2):
    a=string[i]+string[i+1]
    if(a in sub):
        sub[a]+=1
    else:
        sub[a]=1
    i+=1
z=max(sub.values())
for i in sub.keys():
    if(sub[i]==z):
        print(i)
        break;
    
    
