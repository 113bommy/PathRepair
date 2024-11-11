n,m = map(int, input().split());
probdiffs = list(map(int, input().split()));

#a = dict();
#a = [0]*n;
#ans = [];
a = dict();
for i in probdiffs:
    #if i not in a: #a.add(i,1);
    #if a[i]==0: a[i]
    #else: temp1 = a[i]; a.pop(i); a.add(i,temp1+1);
    
    #a[probdiffs[i]-1]+=1;
#    if all(a):
#        a = [j-1 for j in a]; print(1,end='',sep='');
#        ans.append('1');
#    else: print(0,end='',sep='');
#    else: ans.append('0');
#    #print(len(set(probdiffs[0:i+1]))==n, sep='');
    #k = probdiffs[i-1];
    if i in a: a[i]+=1;
    else: a[i]=1;
    if len(a)==n:
        #print(a);
        a2 = dict(); 
        for j in a:
            if a[j]>1: a2[j]=a[j]-1;
        a = a2;
        print(1,end='',sep='');
        #print(a);
    else: print(0,end='',sep='');
    #print(a);
    
#print(''.join(ans));
