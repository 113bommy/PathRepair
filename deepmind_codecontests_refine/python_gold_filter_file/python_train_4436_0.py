
def Check(Mat,Row,Col,TotalSum):
    N=len(Mat)
    M=len(Mat[0])
    SummTillNow=Row[0]*M+Col[0]*N
    for i in range(0,N):
        for j in range(0,M):
            if not (i==0 and j==0):
                if Mat[i][j]==0:
                    if (i in Row and Row[i]!=0) or (j in Col and Col[j]!=0):
                        return False
                    Row[i]=0
                    Col[j]=0
                elif i in Row and j in Col:
                    Val=Row[i]+Col[j]
                    if Val != Mat[i][j]:
                        return False
                elif i in Row:
                    Val=Mat[i][j]-Row[i]
                    if Val<0:
                        return False
                    Col[j]=Val
                    SummTillNow+=N*Val
                elif j in Col:
                    Val=Mat[i][j]-Col[j]
                    if Val<0:
                        return False
                    Row[i]=Val
                    SummTillNow+=M*Val
    if SummTillNow==TotalSum:
        return True
    return False


N,M=map(int,input().strip().split())
Mat=[]
for i in range(N):
    Mat.append(list(map(int,input().strip().split())))
Num=Mat[0][0]
TotalSum=0
Min_Count=float("inf")
for l in Mat:
    TotalSum+=sum(l)
for i in range(0,Num+1):
    Row={}
    Col={}
    Row[0]=i
    Col[0]=Num-i
    res=Check(Mat,Row,Col,TotalSum)
    if res:
        Count=0
        for k,v in Row.items():
            Count+=v
        for k,v in Col.items():
            Count+=v
        if Min_Count>Count:
            Min_Count=min(Min_Count,Count)
            AnsRow=Row
            AnsCol=Col
if Min_Count==float("inf"):
    print(-1)
else:
    print(Min_Count)
    for k,v in AnsRow.items():
        for cnt in range(v):
            print("row",k+1)
    for k,v in AnsCol.items():
        for cnt in range(v):
            print("col",k+1)




