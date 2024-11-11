n = int(input())
lis=[]
slope=[]
dis=[]
for i in range(n):
    a,b=map(int,input().split())
    lis.append([a,b])
lis.append(lis[0])
if n%2!=0:
    print("NO")
    exit()
#print(lis)    
for i in range(1,n+1):
    a,b=lis[i]
    c,d=lis[i-1]
    if c-a==0:
        sl='in'
    else:
        sl=(b-d)/(c-a)
    di = ((a-c)**2 + (d-b)**2)
    slope.append(sl)
    dis.append(di)
#print(slope,dis)          
for i in range(n//2):
#    print(slope[i],slope[n//2 +i])
    if slope[i]!=slope[n//2 + i] or dis[i]!=dis[n//2 +i]:
        print("NO")
        exit()
print("YES")                
        

