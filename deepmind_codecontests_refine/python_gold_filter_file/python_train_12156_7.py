n,m=map(int,input().split())
l=[list(map(str,input())) for i in range(n)]
ch=0
for i in range(n):
    for j in range(m):
        if l[i][j]==".":
            if j-1 >=0:
                if l[i][j-1]=="*":
                    ch=1
                    print("NO")
                    break
            if j+1<=m-1:
                if l[i][j+1]=="*":
                    ch=1
                    print("NO")
                    break
            if i-1 >=0:
                if l[i-1][j]=="*":
                    ch=1
                    print("NO")
                    break
            if i+1 <=n-1:
                if l[i+1][j]=="*":
                    ch=1
                    print("NO")
                    break
            if j-1 >=0 and i-1 >=0:
                if l[i-1][j-1]=="*":
                    ch=1
                    print("NO")
                    break
                
            if j-1 >=0 and i+1 <=n-1:
                if l[i+1][j-1]=="*":
                    ch=1
                    print("NO")
                    break
            if j+1 <=m-1 and i-1 >=0:
                if l[i-1][j+1]=="*":
                    ch=1
                    print("NO")
                    break
            if j+1 <=m-1 and i+1 <=n-1:
                if l[i+1][j+1]=="*":
                    ch=1
                    print("NO")
                    break
        else:
            if l[i][j]!="*":
                co=int(l[i][j])
                #1print(co)
                if j-1 >=0:
                    if l[i][j-1]=="*":
                        co-=1
                    
                if j+1<=m-1:
                    if l[i][j+1]=="*":
                        co-=1
                        
                if i-1 >=0:
                    if l[i-1][j]=="*":
                        co-=1
                        
                if i+1 <=n-1:
                    if l[i+1][j]=="*":
                        co-=1
                        
                if j-1 >=0 and i-1 >=0:
                    if l[i-1][j-1]=="*":
                        co-=1
                        
                    
                if j-1 >=0 and i+1 <=n-1:
                    if l[i+1][j-1]=="*":
                        co-=1
                        
                if j+1 <=m-1 and i-1 >=0:
                    if l[i-1][j+1]=="*":
                        co-=1
                        
                if j+1 <=m-1 and i+1 <=n-1:
                    if l[i+1][j+1]=="*":
                        co-=1
                if co!=0:
                    ch=1
                    print("NO")
                    break
    if ch:
        break
                    
if not ch:
    print("YES")
                