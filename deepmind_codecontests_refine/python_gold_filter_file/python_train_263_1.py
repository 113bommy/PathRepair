n=int(input())

L=[]

for j in range(n):
    ch=input().split()
    s,d=int(ch[0]),int(ch[1])
    if j==0:
       
        print(s,d+s-1)
        L.append([s,s+d-1])
        L.sort()
    else:
        B=True
        C=True
        
        
        for i in range(len(L)):
            
            if i<(len(L)-1) and s>L[i][1] and s+d-1<L[i+1][0]:
                print(s,s+d-1)
                L.append([s,s+d-1])
                L.sort()
                C=False

                break
            
            if L[i][1]>=s>=L[i][0] or L[i][0]<=(s+d-1)<=L[i][1] or (s<=L[i][0] and (s+d-1)>=L[i][1]):
                B=False
                break
        if B and C:
            print(s,s+d-1)
            L.append([s,s+d-1])
            L.sort()
            C=False
        if C:
            if d<L[0][0]:
                print(1,d)
                L.append([1,d])
                L.sort()
                C=False
            else:
                for i in range(len(L)):
                    if i<(len(L)-1) and (L[i][1]+d)<L[i+1][0]:
                        print(L[i][1]+1,L[i][1]+d)
                        L.append([L[i][1]+1,L[i][1]+d])
                        L.sort()
                        C=False
                        break
        
        if not B and C:
            
            print(L[len(L)-1][1]+1,L[len(L)-1][1]+d)
            L.append([L[len(L)-1][1]+1,L[len(L)-1][1]+d])
            L.sort()
          
                        
