# Python code to sort the tuples using second element  
# of sublist Function to sort using sorted() 
def Sort(sub_li): 
  
    # reverse = None (Sorts in Ascending order) 
    # key is set to sort using second element of  
    # sublist lambda has been used 
    return(sorted(sub_li, key = lambda x: x[1])) 
    
    
s=input().rstrip()
x=list(s)
n=int(input())
if n>=len(x):
    print(0)
else:
    l=[0]*26;
    for i in range(0,len(x)):
        l[ord(x[i])-97]+=1;
    q=[]
    for i in range(0,len(l)):
        if l[i]!=0:
            D=[]
            D.append(chr(i+97))
            D.append(l[i])
            q.append(D)
    q=Sort(q)
    #print(q)
    C=0;
    S=0;
    w=[]
    for i in range(0,len(q)):
        S+=q[i][1];
        if(S<=n):
            w.append(q[i][0]);
        else:
            break;
    res=[];
    for i in range(0,len(x)):
        if x[i] in w:
            continue;
        else:
            res.append(x[i])
    V=0;
    for i in range(0,26):
        if chr(i+97) in res:
            V+=1;
    print(V)
    print("".join(res))